//
//  CommandRecognition.swift
//  Pepper
//
//  Created by Brandon Mowat on 2017-01-06.
//  Copyright © 2017 Brandon Mowat. All rights reserved.
//

import Foundation

class CommandRecognition {
    
    let hue = Hue()
    
    init() {}
    
    public func recognizeCommand(_ command: String) {
        
        let commandWordsArray = command.characters.split(separator: " ")
        
        // TODO: parse commandWordsArray to identify greetings and other shit...
        
    }
    
}
