//
//  ViewController.swift
//  TrigCalculator
//
//  Created by Nastya Bekesheva on 04.04.2022.
//

import UIKit
import Foundation


class SinViewController: UIViewController {
    
    @IBOutlet var slider: UISlider!
    @IBOutlet var xText: UITextField!
    @IBOutlet var sinText: UILabel!
    @IBOutlet var xInRadText: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    @IBAction func sliderValueChanged(_ sender: UISlider) {
        let currentValue = Double(sender.value)
        xText.text = String(format: "%.03f", currentValue)
    }
    
    @IBAction func calculateButtonPressed(_ sender: Any) {
        
        
        if let xValue = xText.text{
            if let xValue = Double(xValue){
                let radValue = xValue * Double.pi / 180
                let sinValue = sin(radValue)
                sinText.text = String(format: "sin(x) = %.03f", sinValue)
                xInRadText.text = String(format: "x in rad = %.03f", radValue)
                addToHistory(xValue, sinValue)
                
            }
            
        }
        else{
            sinText.text = "sin(x) = "
        }
    }
    
    func addToHistory(_ xValue: Double, _ sinValue: Double){
        let answer = String(format: "sin(%.03f°) = %.03f", xValue, sinValue)
        HistoryViewController.historyArray.append(answer)
        
    }
}
