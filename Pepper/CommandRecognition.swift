//
//  CommandRecognition.swift
//  Pepper
//
//  Created by Brandon Mowat on 2017-01-06.
//  Copyright © 2017 Brandon Mowat. All rights reserved.
//

import Foundation

enum Target {
    case all, living, bedroom
}

enum Action {
    case down, up, on, off
}

class CommandRecognition {
    
    let hue = Hue()
    
    init() {}
    
    private func convertToStringArray(_ commandArray: Array<String.CharacterView.SubSequence>) -> Array<String> {
        
        var arr: Array<String> = []
        
        for seq in commandArray {
            arr.append(String(seq))
        }
        
        return arr
    }
    
    func parseCommandString(_ command: String) -> (Target, Action) {
        
        let commandWordsArray = convertToStringArray(command.characters.split(separator: " "))
        
        // TODO: parse commandWordsArray to identify greetings and other shit...
        let first = commandWordsArray[0]
        let second = commandWordsArray[1]
        
        // case where we preface our command with a greeting
        if first == "hello" || first == "hey" || first == "pepper" || first == "hi" {
            
            switch (second, commandWordsArray[2]) {
            case ("could", "you"):
                return interpretCommand(Array(commandWordsArray[3..<commandWordsArray.count]))
            default:
                return interpretCommand(Array(commandWordsArray[1..<commandWordsArray.count]))
            }
            
        } else {
            
            return interpretCommand(Array(commandWordsArray))
            
        }
        
    }
    
    private func interpretCommand(_ commandArray: Array<String>) -> (Target, Action) {
        
        let the = commandArray.index(of: "the")
        print(the!)
        let targetStrings = Array(commandArray[the!+1..<commandArray.count]) as Array<String>
        var targAct: (Target, Action) = (.all, .on) // target and action
        
        //set Target
        if (targetStrings[0] == "lights" && targetStrings.contains("the")) {
            let the = targetStrings.index(of: "the")
            let locationStrings = targetStrings[the!+1..<targetStrings.count]
            var locationString: String = ""
            var count = locationStrings.count
            for str in locationStrings {
                locationString += str
                if count != 1 {
                    locationString += " "
                }
                count -= 1
            }
            switch locationString {
            case "living room":
                targAct.0 = .living
            break // set living room
            case "bedroom", "bed room":
                targAct.0 = .bedroom
            break // set bedroom
            default:
                break // do a thing
            }
            
        } else if targetStrings[targetStrings.count-1] == "lights" && targetStrings.count == 1 {
            print("lights")
            targAct.0 = .all
        }
        
        // set Action
        switch commandArray[0] {
        case "turn":
            switch commandArray[1] {
            case "on":
                print("turn on")
                targAct.1 = .on
            case "off":
                print("turn off")
                targAct.1 = .off
            case "up":
                print("turn up")
                targAct.1 = .up
            case "down":
                print("turn down")
                targAct.1 = .down
            default:
                break
            }
        case "dim", "in":
            print("dim")
            targAct.1 = .down
        case "brighten", "lighten":
            print("turn up")
            targAct.1 = .up
        default:
            break
        }
        
        return targAct
        
    }
    
}
