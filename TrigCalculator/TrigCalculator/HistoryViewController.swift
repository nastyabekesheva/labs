//
//  HistoryViewController.swift
//  TrigCalculator
//
//  Created by Nastya Bekesheva on 04.04.2022.
//

import UIKit

class HistoryViewController: UIViewController {
    
    static var historyArray : [String] = []

    @IBOutlet var historyLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    override func viewWillAppear(_ animated: Bool) {
        historyLabel.numberOfLines = HistoryViewController.historyArray.count
        
        let reversedHistory = HistoryViewController.historyArray.reversed()
        historyLabel.text = reversedHistory.joined(separator: "\n")
    }

    @IBAction func clearButtonPressed(_ sender: Any) {
        HistoryViewController.historyArray.removeAll()
        
        historyLabel.text = ""
    }
    
    



}
