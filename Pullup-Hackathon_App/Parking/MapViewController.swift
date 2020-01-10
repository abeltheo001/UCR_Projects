//
//  MapViewController.swift
//  Parking
//
//  Created by Abel Theo on 11/9/19.
//  Copyright © 2019 Snehal Mulchandani. All rights reserved.
//

import Foundation
import UIKit
import MapKit
import CoreLocation


class MapViewController: UIViewController {

    //@IBOutlet weak var mapSView: MKMapView!
    
    @IBOutlet weak var mapSView: MKMapView!
    
    let locationManager = CLLocationManager()
    let regionInMeters: Double = 10000
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        checkLocationServices()
    }
    
    func setUpLocationManager(){
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
    }
    
    func centerViewOnUserLocation(){
        if let location = locationManager.location?.coordinate {
            let region = MKCoordinateRegion.init(center: location, latitudinalMeters: regionInMeters, longitudinalMeters:  regionInMeters)
            mapSView.setRegion(region, animated: true)
        }
    }
     
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    @IBAction func Retreat(_ sender: AnyObject) {
        self.performSegue(withIdentifier: "Retreater", sender: self)
    }
    
    func checkLocationServices(){
        if CLLocationManager.locationServicesEnabled(){
            setUpLocationManager()
            checkLocationAuthorization()
        } else{
            //code let user know turn on
        }
    }
    func checkLocationAuthorization() {
        switch CLLocationManager.authorizationStatus(){
        case .authorizedWhenInUse:
            //Do map stuff
            centerViewOnUserLocation()
            break
        case .denied:
            //show alert for displaying permission
            break
        case .notDetermined:
            locationManager.requestWhenInUseAuthorization()
        case .restricted:
            //alert
            break
        case .authorizedAlways:
            break
        }
    }
    
}


extension MapViewController: CLLocationManagerDelegate{
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        //code
    }
}
