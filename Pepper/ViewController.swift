//
//  ViewController.swift
//  Pepper
//
//  Created by Brandon Mowat on 2016-12-29.
//  Copyright © 2016 Brandon Mowat. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var viewHeader: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        self.viewHeader.center.y += 10.0
        self.viewHeader.isOpaque = false
    }
    
    override func viewDidAppear(_ animated: Bool) {
        UIView.animate(withDuration: 0.8, animations: {
           self.viewHeader.center.y -= 10.0
            self.viewHeader.isOpaque = true
        })
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

