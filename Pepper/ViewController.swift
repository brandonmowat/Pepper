//
//  ViewController.swift
//  Pepper
//
//  Created by Brandon Mowat on 2016-12-29.
//  Copyright © 2016 Brandon Mowat. All rights reserved.
//

import UIKit
import Speech
import googleapis

let SAMPLE_RATE = 16000

class ViewController: UIViewController, AudioControllerDelegate {
    
    let hue = Hue() // initialize hue
    let user = User() // initialize user
    let speak = Speak() // init speak object
    let commandRecognition = CommandRecognition()
    
    @IBOutlet weak var viewHeader: UILabel!
    @IBOutlet weak var micButton: UIButton!
    @IBOutlet weak var BlurView: UIVisualEffectView!
    @IBOutlet weak var result: UITextView!
    
    
    var audioData: NSMutableData!
    var micButtonIsActive: Bool = false
    
    @IBAction func buttonDown(_ sender: UIButton) {
        if (self.micButtonIsActive) {
        
            self.stopAudio()
            self.micButtonIsActive = false
            return
            
        }
        self.micButtonIsActive = true
        UIView.animate(withDuration: 0.3, animations: {
            self.updateBlur(.dark)
            self.micButton.backgroundColor = .white
            self.micButton.transform = CGAffineTransform(scaleX: 2.0, y: 2.0)
            self.viewHeader.textColor = .white
        })
        self.recordAudio()
    }
    
    @IBAction func buttonUp(_ sender: UIButton) {

    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        AudioController.sharedInstance.delegate = self
        self.user.updateInternalIP()
    }
    
    // before view loads
    override func viewWillAppear(_ animated: Bool) {
        self.viewHeader.center.y += 10.0
        self.viewHeader.alpha = 0.0
        self.micButton.layer.cornerRadius = 23
    }
    
    // after view loads
    override func viewDidAppear(_ animated: Bool) {
        self.animateViewHeader()
    }
    
    // Start audio stream
    func recordAudio() {
        let audioSession = AVAudioSession.sharedInstance()
        do {
            try audioSession.setCategory(AVAudioSessionCategoryRecord)
        } catch {
        
        }
        audioData = NSMutableData()
        _ = AudioController.sharedInstance.prepare(specifiedSampleRate: SAMPLE_RATE)
        SpeechRecognitionService.sharedInstance.sampleRate = SAMPLE_RATE
        _ = AudioController.sharedInstance.start()
    }
    
    // Stop audio stream
    func stopAudio() {
        self.micButtonIsActive = false
        UIView.animate(withDuration: 0.3, animations: {
            self.updateBlur(.light)
            self.micButton.backgroundColor = .black
            self.micButton.transform = CGAffineTransform(scaleX: 1, y: 1)
            self.viewHeader.textColor = .black
            
        })
        _ = AudioController.sharedInstance.stop()
        SpeechRecognitionService.sharedInstance.stopStreaming()
        
    }
    
    // Process the incoming data from the mic
    func processSampleData(_ data: Data) -> Void {
        audioData.append(data)
        // We recommend sending samples in 100ms chunks
        let chunkSize : Int /* bytes/chunk */ = Int(0.1 /* seconds/chunk */
            * Double(SAMPLE_RATE) /* samples/second */
            * 2 /* bytes/sample */);
        
        if (audioData.length > chunkSize) {
            SpeechRecognitionService.sharedInstance.streamAudioData(audioData,
                                                                    completion:
                { (response, error) in
                    if let error = error {
                        print(error)
                    } else if let response = response {
                        var finished = false
                        for result in response.resultsArray! {
                            print(result)
                            if let result = result as? StreamingRecognitionResult {
                                //self.result.text = ((result.alternativesArray[0] as! SpeechRecognitionAlternative).transcript)
                                if result.isFinal {
                                    let resString = ((result.alternativesArray[0] as! SpeechRecognitionAlternative).transcript)
                                    //self.result.text = resString
                                    self.doTheThings(inputString: resString!)
                                    finished = true
                                }
                            }
                        }
                        if finished {
                            self.stopAudio()
                        }
                    }
            })
            self.audioData = NSMutableData()
        }
    }
    
    func doTheThings(inputString input: String) {
        let targetAction = commandRecognition.parseCommandString(input)
        switch targetAction {
        case (.all, .on):
            self.hue.turnOnAllLights()
        case (.all, .off):
            self.hue.turnOffAllLights()
        case (.living, .on):
            self.hue.turnOnLight("6")
        case (.living, .off):
            self.hue.turnOffLight("6")
        case (.bedroom, .on):
            self.hue.turnOnLight("4")
            self.hue.turnOnLight("5")
            self.hue.turnOnLight("6")
        case (.bedroom, .off):
            self.hue.turnOffLight("4")
            self.hue.turnOffLight("5")
            self.hue.turnOffLight("6")
        case (.living, .down):
            self.hue.changeBrightness("down", "6", 50)
        case (.living, .up):
            self.hue.changeBrightness("up", "6", 50)
        default:
            break
        }
//        switch input {
//        case "turn off the living room light":
//            self.hue.turnOffLight("6")
//        case "turn on the living room light":
//            self.hue.turnOnLight("6")
//        case "turn off the lights":
//            self.hue.turnOffAllLights()
//        case "turn on the lights":
//            self.hue.turnOnAllLights()
//        case "turn up the living room", "brighten the living room":
//            self.hue.changeBrightness("up", "6", 50)
//        case "in the living room", "dim the living room", "dim the living room light", "turn down the living room light":
//            self.hue.changeBrightness("down", "6", 50)
//        case "turn up the bedroom", "brighten the bedroom":
//            self.hue.changeBrightness("up", "4", 60)
//            self.hue.changeBrightness("up", "5", 60)
//        case "dim the bedroom", "turn down the bedroom", "in the bedroom":
//            self.hue.changeBrightness("down", "4", 60)
//            self.hue.changeBrightness("down", "5", 60)
//        case "goodnight pepper", "good night pepper", "goodnight", "good night":
//            //self.hue.turnOffAllLights()
//            self.speak.say(sentence: "Goodnight.")
//        default:
//            self.result.text = "I'm not sure what you need me to do 😔"
//            
//        }
    }
    
    /**
     * Some Helper animations
     */
    
    // Fade up and in animation
    func animateViewHeader() {
        UIView.animate(withDuration: 0.5, delay: 0.5, animations: {
            self.viewHeader.center.y -= 10.0
            self.viewHeader.alpha = 1.0
        })
    }
    
    // Update the main view blur to a specified style
    func updateBlur(_ style: UIBlurEffectStyle) {
        BlurView.effect = UIBlurEffect(style: style)
    }
    
    // Mem warn
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

