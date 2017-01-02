//
//  ViewController.swift
//  Pepper
//
//  Created by Brandon Mowat on 2016-12-29.
//  Copyright © 2016 Brandon Mowat. All rights reserved.
//

import UIKit
import Speech

class ViewController: UIViewController, SFSpeechRecognizerDelegate {
    
    let hue = Hue() // initialize hue
    
    @IBOutlet weak var viewHeader: UILabel!
    @IBOutlet weak var micButton: UIButton!
    @IBOutlet weak var BlurView: UIVisualEffectView!
    
    @IBAction func buttonDown(_ sender: UIButton) {
        UIView.animate(withDuration: 0.3, animations: {
            self.updateBlur(.dark)
        })
    }
    @IBAction func buttonUp(_ sender: UIButton) {
        UIView.animate(withDuration: 0.3, animations: {
            self.updateBlur(.extraLight)
        })
    }
    
    private let speechRecognizer = SFSpeechRecognizer(locale: Locale.init(identifier: "en-US"))  // 1

    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        micButton.isEnabled = false
        
        speechRecognizer?.delegate = self
        
        SFSpeechRecognizer.requestAuthorization { (authcode) in
        
            var isButtonEnabled: Bool = false
            
            switch authcode {
            case .authorized:
                isButtonEnabled = true
                break
            case .denied:
                isButtonEnabled = false
                break
            case .notDetermined:
                isButtonEnabled = false
                break
            case .restricted:
                isButtonEnabled = false
                break
            }
            
            OperationQueue.main.addOperation() {
            
                self.micButton.isEnabled = isButtonEnabled
            
            }
        
        }
        
    }
    
    override func viewWillAppear(_ animated: Bool) {
        self.viewHeader.center.y += 10.0
        self.viewHeader.alpha = 0.0
        self.micButton.layer.cornerRadius = 23
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.animateViewHeader()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func animateViewHeader() {
        UIView.animate(withDuration: 0.5, delay: 0.5, animations: {
            self.viewHeader.center.y -= 10.0
            self.viewHeader.alpha = 1.0
        })
    }
    
    func updateBlur(_ style: UIBlurEffectStyle) {
    
        BlurView.effect = UIBlurEffect(style: style)
    
    }


}

