//
//  Spacecraft.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Spacecraft{
    
    private var engine: Engine
    private var model: String
    var captain: Personnel?
    var personnel: [Personnel]?
    var solarPanels: [SolarPanel]?
    var amountOfScientists: Int = 0
    var amountOfEngineers: Int = 0
    
    init(model: String, engine: Engine, captain: Personnel?, personnel: [Personnel]?){
        self.model = model
        self.engine = engine
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
    
    func startFlight(){
        print("Preparing for flight...")
        if amountOfEngineers != 0 && amountOfScientists != 0{
            if let captain = captain {
                switch captain.proffesion{
                case .engineer:
                    let updatedCaptain = Engineer(person: captain)
                    if updatedCaptain.checkEngine(engine: engine)!{
                        if let solarPanels = solarPanels {
                            var scientist = Scientist()
                            for person in personnel!{
                                if person.proffesion == .scientist{
                                    scientist = Scientist(person: person)
                                }
                            }
                            var panelsState = [Bool]()
                            for panel in solarPanels{
                                panelsState.append(scientist.checkPanels(panel: panel)!)
                            }
                            if panelsState.contains(true){
                                print("Ready to fly!\nSetting off...\nSuccess, your now flying!")
                            }
                            else{
                                print("You should turn your pannels on")
                                print("Ready to fly!\nSetting off...\nSuccess, your now flying!")
                            }
                        }
                        else{
                            print("Cannot fly without solar panels")
                        }
                        
                    }
                    else{
                        print("Please turn the engine on")
                    }
                case .scientist:
                    let updatedCaptain = Scientist(person: captain)
                    var engineer = Engineer()
                    for person in personnel!{
                        if person.proffesion == .engineer{
                            engineer = Engineer(person: person)
                            if engineer.checkEngine(engine: engine)!{
                                if let solarPanels = solarPanels {
                                    var panelsState = [Bool]()
                                    for panel in solarPanels{
                                        panelsState.append(updatedCaptain.checkPanels(panel: panel)!)
                                    }
                                    if panelsState.contains(true){
                                        print("Ready to fly!\nSetting off...\nSuccess, your now flying!")
                                    }
                                    else{
                                        print("You should turn your pannels on")
                                        print("Ready to fly!\nSetting off...\nSuccess, your now flying!")
                                    }
                                }
                                else{
                                    print("Cannot fly without solar panels")
                                }
                            }
                            else{
                                print("Cannot fly without engine")
                            }
                        }
                    }
                    
                    
                case .none:
                    print("Imposter on board")
                }
            }
        }
        else if amountOfEngineers == 0{
            print("Cannot fly without engineers")
        }
        else if amountOfScientists == 0{
            print("Cannot fly without scientists")
        }
        else{
            print("Cannot fly without personnel")
        }
    }
    
}
