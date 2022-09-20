//
//  CosViewController.swift
//  TrigCalculator
//
//  Created by Nastya Bekesheva on 04.04.2022.
//

import UIKit

class CosViewController: UIViewController {
    
    @IBOutlet var slider: UISlider!
    @IBOutlet var xText: UITextField!
    @IBOutlet var cosText: UILabel!
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
                let cosValue = cos(radValue)
                cosText.text = String(format: "cos(x) = %.03f", cosValue)
                xInRadText.text = String(format: "x in rad = %.03f", radValue)
                addToHistory(xValue, cosValue)
            }
            
        }
        else{
            cosText.text = "cos(x) = "
        }
    }
    
    func addToHistory(_ xValue: Double, _ cosValue: Double){
        let answer = String(format: "cos(%.03f°) = %.03f", xValue, cosValue)
        HistoryViewController.historyArray.append(answer)
        
    }
}
