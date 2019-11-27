//
//  ViewController.swift
//  Parking
//
//  Created by Snehal Mulchandani on 11/9/19.
//  Copyright © 2019 Snehal Mulchandani. All rights reserved.
//

import Foundation
import UIKit

class HomeViewController: UIViewController {
    
    @IBAction func FindSpot(_ sender: AnyObject) {
        self.performSegue(withIdentifier: "MapViewSegue", sender: self)
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    }



