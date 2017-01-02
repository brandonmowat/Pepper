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
    
    let hue = Hue()
    
    @IBOutlet weak var viewHeader: UILabel!
    @IBOutlet weak var micButton: UIButton!
    
    
    private let speechRecognizer = SFSpeechRecognizer(locale: Locale.init(identifier: "en-US"))  //1
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        //microphoneButton.isEnabled = false  //2

    }
    
    override func viewWillAppear(_ animated: Bool) {
        self.viewHeader.center.y += 10.0
        self.viewHeader.alpha = 0.0
        self.micButton.layer.cornerRadius = 23
    }
    
    override func viewDidAppear(_ animated: Bool) {
        UIView.animate(withDuration: 0.5, delay: 0.5, animations: {
            self.viewHeader.center.y -= 10.0
            self.viewHeader.alpha = 1.0
        })
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

