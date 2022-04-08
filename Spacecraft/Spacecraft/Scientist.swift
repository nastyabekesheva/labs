//
//  Scientist.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Scientist: Personnel{
    
    override init(){super.init()}
    
    override init(_ name: String){
        super.init(name)
        proffesion = .scientist
    }
    
    init(person: Personnel){
        super.init(person.getName())
        proffesion = .scientist
    }
    
    deinit{
        print("ok")
        if (self.occupation?.amountOfScientists) != nil{
            var temp = Int((self.occupation?.amountOfScientists)!)
            self.occupation?.amountOfScientists = temp
            print(self.occupation?.amountOfScientists)
        }
    }
    
    func checkPanels(panel: SolarPanel) -> Bool?{
        
        switch self.state{
        case .awake:
            switch panel.state{
            case .on:
                return true
            case .off:
                return false
            }
        case .asleep:
            print("Cannot check panels while sleeping")
            return nil
        }
    }
    
    func setPanelState(panel: SolarPanel, state: SolarPanel.State){
        panel.state = state
    }
}
