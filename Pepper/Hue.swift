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
    
    var baseURL: String = "http://192.168.0.10/api/Od-QyQU7aWiPNJSEWpkgKV7nDh3QMpieLmcjqo6q"
    
    init() {
        
    }
    
    public func getHueData() {
    
        Alamofire.request("https://httpbin.org/put")
            .responseString { response in
                print("Response String: \(response.result.value)")
            }
            .responseJSON { response in
                print("Response JSON: \(response.result.value)")
            }
        
    }
    
    public func turnOffLight(_ lightId: String) {
        
        let parameters: Parameters = ["on": false]

        Alamofire.request("\(baseURL)/lights/\(lightId)/state", method: .put, parameters: parameters, encoding: JSONEncoding.default)
            .responseString { response in
                print("Response String: \(response.result.value)")
            }
            .responseJSON { response in
                print("Response JSON: \(response.result.value)")
            }
    
    }
    
    public func turnOnLight(_ lightId: String) {
        
        let parameters: Parameters = ["on": true]
        
        Alamofire.request("\(baseURL)/lights/\(lightId)/state", method: .put, parameters: parameters, encoding: JSONEncoding.default)
            .responseString { response in
                print("Response String: \(response.result.value)")
            }
            .responseJSON { response in
                print("Response JSON: \(response.result.value)")
        }
        
    }

}
