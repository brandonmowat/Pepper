//
//  User.swift
//  Pepper
//
//  Created by Brandon Mowat on 2017-01-15.
//  Copyright © 2017 Brandon Mowat. All rights reserved.
//

import Foundation
import Alamofire

class User {
    
    var defaults = UserDefaults.standard
    var ipAddress: String?

    init() {
        
        if let internalIP = (self.defaults.object(forKey: "ipAddress")) {
            self.ipAddress = internalIP as? String
        }
        
    }
    
    func updateInternalIP() {
        Alamofire.request("https://www.meethue.com/api/nupnp")
            .responseJSON { response in
                if let ip = ((response.result.value) as! Array<Dictionary<AnyHashable, Any>>)[0]["internalipaddress"] {
                    print(ip)
                    self.defaults.set(ip, forKey: "ipAddress")
                }
        }
    }
    
    func getInternalIP() -> String? {
        return self.defaults.object(forKey: "ipAddress") as! String?
    }
    
    

}
