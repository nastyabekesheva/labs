//
//  ViewController.swift
//  BasicCalculator
//
//  Created by Nastya Bekesheva on 25.04.2022.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var firstNumberText: UITextField!
    @IBOutlet var secondNumberText: UITextField!
    @IBOutlet var resultLabel: UILabel!
    @IBOutlet var historyLabel: UILabel!
    var history: [String] = []
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func plusButtonPressed(_ sender: Any) {
        
        if let a = Int(firstNumberText.text ?? "0"){
            if let b = Int(secondNumberText.text ?? "0"){
                let result = a + b
                resultLabel.text = "\(a) + \(b) = \(result)"
                
                addHistory(result: resultLabel.text ?? "")
            }
        }
    }
    
    @IBAction func minusButtonPressed(_ sender: Any) {
        
        if let a = Int(firstNumberText.text ?? "0"){
            if let b = Int(secondNumberText.text ?? "0"){
                let result = a - b
                resultLabel.text = "\(a) - \(b) = \(result)"
                
                addHistory(result: resultLabel.text ?? "")
            }
        }
    }
    
    @IBAction func clearButtonPressed(_ sender: Any) {
        
        historyLabel.text = ""
    }
    
    func addHistory(result: String){
        history.insert(result, at: 0)
        historyLabel.numberOfLines = history.count
        historyLabel.text = history.joined(separator: "\n")
    }
    
}

