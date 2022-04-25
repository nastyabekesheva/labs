//
//  Spacecraft.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Spacecraft{
    
    var engine: Engine
    private var model: String
    var captain: Personnel?
    var personnel: [Personnel]?
    var solarPanels: [SolarPanel]?
    var amountOfScientists: Int = 0
    var amountOfEngineers: Int = 0
    
    init(model: String, engine: String, captain: Personnel?, personnel: [Personnel]?){
        self.model = model
        self.engine = Engine(engine)
        self.captain = captain
        self.personnel = personnel
        self.solarPanels = nil
        self.personnel = [captain!]
        switch captain!.proffesion{
        case .engineer:
            amountOfEngineers += 1
        case .scientist:
            amountOfScientists += 1
        case .none:
            break
        }
        captain!.occupation = self
    }
    
    deinit{
        print("Bye")
    }
    
    func addPersonnel(_ name: String) -> Personnel{
        let temp = Personnel(name)
        if let _ = personnel {
            personnel?.append(temp)
        }
        else{
            personnel = [temp]
        }
        temp.occupation = self
        
        return temp
    }
    func addPersonnel(person: Personnel){
        if let _ = personnel {
            personnel?.append(person)
        }
        else{
            personnel = [person]
        }
        switch person.proffesion{
        case .engineer:
            amountOfEngineers += 1
        case .scientist:
            amountOfScientists += 1
        case .none:
            break
        }
        person.occupation = self

    }
    func addPanel(_ name: String) -> SolarPanel{
        let temp = SolarPanel(name)
        if let _ = solarPanels {
            solarPanels?.append(temp)
        }
        else{
            solarPanels = [temp]
        }
        
        return temp
    }
    func addPanel(panel: SolarPanel){
        if let _ = solarPanels {
            solarPanels?.append(panel)
        }
        else{
            solarPanels = [panel]
        }
    }
    
    func getModel() -> String{
        return self.model
    }
    
}
