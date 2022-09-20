//
//  Personnel.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Personnel{
    
    private let name: String
    var state: State
    var proffesion: Proffesion?
    var occupation: Spacecraft?
    
    enum State{
        case asleep, awake
    }
    
    enum Proffesion{
        case scientist, engineer
    }
    
    init(){
        self.name = ""
        self.state = .asleep
        self.proffesion = nil
        self.occupation = nil
    }
    
    init(_ name: String){
        self.name = name
        self.state = .awake
        self.proffesion = nil
        self.occupation = nil
    }
    
    func startFlight(spacecraft: Spacecraft){
        if self.occupation?.getModel() == spacecraft.getModel(){
            print("Preparing for flight...")
            if spacecraft.amountOfEngineers != 0 && spacecraft.amountOfScientists != 0{
                if let captain = spacecraft.captain {
                    switch captain.proffesion{
                    case .engineer:
                        let updatedCaptain = Engineer(person: captain)
                        if updatedCaptain.checkEngine(engine: occupation!.engine)!{
                            if let solarPanels = spacecraft.solarPanels {
                                var scientist = Scientist()
                                for person in spacecraft.personnel!{
                                    if person.proffesion == .scientist{
                                        scientist = Scientist(person: person)
                                    }
                                }
                                var panelsState = [Bool]()
                                for panel in occupation!.solarPanels!{
                                    panelsState.append(scientist.checkPanels(panel: panel)!)
                                }
                                if !panelsState.contains(false){
                                    print("Ready to fly!\nSetting off...\nSuccess, you're now flying!")
                                }
                                else{
                                    print("You should turn your pannels on")
                                    print("Ready to fly!\nSetting off...\nSuccess, you're flying now!")
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
                        for person in spacecraft.personnel!{
                            if person.proffesion == .engineer{
                                engineer = Engineer(person: person)
                                if engineer.checkEngine(engine: occupation!.engine)!{
                                    if let solarPanels = spacecraft.solarPanels {
                                        var panelsState = [Bool]()
                                        for panel in occupation!.solarPanels!{
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
            else if spacecraft.amountOfEngineers == 0{
                print("Cannot fly without engineers")
            }
            else if spacecraft.amountOfScientists == 0{
                print("Cannot fly without scientists")
            }
            else{
                print("Cannot fly without personnel")
            }
        }
        else{
            print("Procces not authorised")
        }
    }
    
    func wakeUp(){
        self.state = .awake
        print("\(self.name) is now awake")
    }
    
    func sleep(){
        self.state = .asleep
        print("\(self.name) is now sleeping")
    }
    
    func getName() -> String{
        return self.name
    }
    
    deinit{
        print("Deleteing unnecessary object")
    }
}
