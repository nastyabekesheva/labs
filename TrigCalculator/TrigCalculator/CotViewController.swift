//
//  CotViewController.swift
//  TrigCalculator
//
//  Created by Nastya Bekesheva on 04.04.2022.
//

import UIKit

class CotViewController: UIViewController {

    @IBOutlet var slider: UISlider!
    @IBOutlet var xText: UITextField!
    @IBOutlet var cotText: UILabel!
    @IBOutlet var xInRadText: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    @IBAction func sliderValueChanged(_ sender: UISlider) {
        let currentValue = Double(sender.value)
        xText.text = String(format: "%.01f", currentValue)
    }
    
    @IBAction func calculateButtonPressed(_ sender: Any) {
        
        
        if let xValue = xText.text{
            if let xValue = Double(xValue){
                let radValue = xValue * Double.pi / 180
                let cotValue = 1/tan(radValue)
                cotText.text = String(format: "cot(x) = %.01f", cotValue)
                xInRadText.text = String(format: "x in rad = %.01f", radValue)
                addToHistory(xValue, cotValue)
            }
            
        }
        else{
            cotText.text = "cot(x) = "
        }
    }
    
    func addToHistory(_ xValue: Double, _ cotValue: Double){
        let answer = String(format: "cot(%.01f°) = %.01f", xValue, cotValue)
        HistoryViewController.historyArray.append(answer)
        
    }
    


}
