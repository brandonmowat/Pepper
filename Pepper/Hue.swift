//
//  Hue.swift
//  Pepper
//
//  Created by Brandon Mowat on 2017-01-01.
//  Copyright © 2017 Brandon Mowat. All rights reserved.
//

import Foundation
import Alamofire

class Hue {
    
    var baseURL: String = "http://192.168.0.14/api/Od-QyQU7aWiPNJSEWpkgKV7nDh3QMpieLmcjqo6q"
    
    init() {
        
    }
    
    func getHueData(completion: @escaping (_ data: Any) -> Void) {
    
        Alamofire.request(self.baseURL)
            .responseJSON { response in
                print("Light Data: \(response.result.value)")
                completion(response.result.value ?? "")
            }
        
    }
    
    public func turnOffAllLights() {
    
        self.getHueData(completion: {(data: Any) -> Void in
            
            let lightsData = (data as! NSDictionary)["lights"]
            
            for (key, _) in lightsData as! NSDictionary {
            
                self.turnOffLight(key as! String)
            
            }
        
        })
        
    }
    
    public func turnOnAllLights() {
        
        self.getHueData(completion: {(data: Any) -> Void in
            
            let lightsData = (data as! NSDictionary)["lights"]
            
            for (key, _) in lightsData as! NSDictionary {
                
                self.turnOnLight(key as! String)
                
            }
            
        })
        
    }
    
    public func turnOffLight(_ lightId: String) {
        
        let parameters: Parameters = ["on": false]

        Alamofire.request("\(baseURL)/lights/\(lightId)/state", method: .put, parameters: parameters, encoding: JSONEncoding.default)
            .responseJSON { response in
                print("Response JSON: \(response.result.value)")
            }
    
    }
    
    public func turnOnLight(_ lightId: String) {
        
        let parameters: Parameters = ["on": true] // Parameters is an Alamofire object
        
        Alamofire.request("\(baseURL)/lights/\(lightId)/state", method: .put, parameters: parameters, encoding: JSONEncoding.default)
            .responseJSON { response in
                print("Response JSON: \(response.result.value)")
        }
        
    }
    
    public func changeBrightness(_ upOrDown: String, _ lightId: String, _ amount: Int) {
        
        self.getHueData(completion: {(data: Any) -> Void in
            
            let lightsData = (data as! NSDictionary)["lights"]

            if let bri = (((lightsData as! NSDictionary)[lightId] as!
                NSDictionary)["state"] as! NSDictionary)["bri"] {
                
                var new_bri: Int
                
                switch upOrDown {
                case "up":
                    new_bri = (bri as! Int) + amount
                    if new_bri >= 255 {
                        new_bri = 255
                    }
                default:
                    new_bri = (bri as! Int) - amount
                    if new_bri <= 0 {
                        new_bri = 0
                    }
                }
                
                let parameters: Parameters = ["bri": new_bri]
                
                Alamofire.request("\(self.baseURL)/lights/\(lightId)/state", method: .put, parameters: parameters, encoding: JSONEncoding.default)
                    .responseJSON { response in
                        print("Response JSON: \(response.result.value)")
                }
            
            }
            
        })
    
    }

}
