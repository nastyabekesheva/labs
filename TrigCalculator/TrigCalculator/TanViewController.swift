//
//  TanViewController.swift
//  TrigCalculator
//
//  Created by Nastya Bekesheva on 04.04.2022.
//

import UIKit

class TanViewController: UIViewController {
    
    @IBOutlet var slider: UISlider!
    @IBOutlet var xText: UITextField!
    @IBOutlet var tanText: UILabel!
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
                let tanValue = tan(radValue)
                tanText.text = String(format: "tan(x) = %.03f", tanValue)
                xInRadText.text = String(format: "x in rad = %.03f", radValue)
                addToHistory(xValue, tanValue)
            }
            
        }
        else{
            tanText.text = "tan(x) = "
        }
    }
    
    func addToHistory(_ xValue: Double, _ tanValue: Double){
        let answer = String(format: "tan(%.03f°) = %.03f", xValue, tanValue)
        HistoryViewController.historyArray.append(answer)
        
    }
}
