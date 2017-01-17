//
//  Speak.swift
//  Pepper
//
//  Created by Brandon Mowat on 2017-01-16.
//  Copyright © 2017 Brandon Mowat. All rights reserved.
//

import Foundation
import AVFoundation

class Speak {
    func say(sentence: String) {
        let utterance = AVSpeechUtterance(string: sentence)
        utterance.voice = AVSpeechSynthesisVoice(language: "en-US")
        utterance.pitchMultiplier = 1.2
        utterance.rate = 0.5
        
        let synthesizer = AVSpeechSynthesizer()
        synthesizer.speak(utterance)
    }
}
