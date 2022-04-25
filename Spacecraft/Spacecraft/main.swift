//
//  main.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

var spacecrafts: [Spacecraft] = []
var solarpanels: [SolarPanel] = []
var people: [Personnel] = []
var state = true
print("What would you like to do?\n 1. Create Spacecraft\n 2. Create Solar Panel\n 3. Create Personnel\n 4. Create Scientist\n 5. Create Engineer\n 6. Add Personnel to Spacecraft\n 7. Add Solar Panel to Spacecraft\n 8. Set state for Personnel\n 9. Set state for Spacecraft's Engine\n 10. Set state for Solar Panel\n 11. Fly Spacecraft\n 12. Chage captain\n 13. Exist")
while state{
    let answer = readLine()
    if let answer = Int(answer ?? "w") {
        switch answer{
        case 1:
            print("Set model for Spacecraft: ")
            let model = readLine()
            print("Set model for Spacecraft's Engine: ")
            let engineModel = readLine()
            print("Set name for captain")
            let captain = readLine()
            
            spacecrafts.append(Spacecraft(model: model ?? "no name", engine: engineModel ?? "no name", captain: Personnel(captain ?? "no name"), personnel: nil))
            print("Spacecraft created")
        case 2:
            print("Set model for solar panel: ")
            let model = readLine()
            solarpanels.append(SolarPanel(model ?? "no name"))
            print("Success!")
        case 3:
            print("Set name for person: ")
            let name = readLine()
            people.append(Personnel(name ?? "no name"))
            print("Success!")
        case 4:
            print("Set name for person: ")
            let name = readLine()
            people.append(Scientist(name ?? "no name"))
            print("Success!")
        case 5:
            print("Set name for person: ")
            let name = readLine()
            people.append(Engineer(name ?? "no name"))
            print("Success!")
        case 6:
            var s = 0
            var p = 0
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                if spacecraft.getModel() == model{
                    s += 1
                    print("Enter name of the person: ")
                    let name = readLine()
                    for person in people {
                        if person.getName() == name{
                            p += 1
                            if spacecraft.getModel() != person.occupation?.getModel(){
                                spacecraft.addPersonnel(person: person)
                                print("Successfully added \(name!) to \(model!)!")
                            }
                            else{
                                print("Already on board!")
                            }
                        }
                    }
                    if p == 0{
                        print("Failed to find a person with name \(name!)...\nWould you like to create a person with name \(name!)?(Y/N)")
                        let ans = readLine()?.lowercased()
                        if ans == "y"{
                            people.append(spacecraft.addPersonnel(name!))
                            print("Success!")
                        }
                        else if ans == "n"{
                            print("As you wish")
                        }
                        else{
                            print("Failed to create...")
                        }
                    }
                }
            }
            if s == 0{
                print("Failed to find Spacecraft \(model!)...")
            }
        case 7:
            var s = 0
            var p = 0
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                if spacecraft.getModel() == model{
                    s += 1
                    print("Enter model of solar panel: ")
                    let solarModel = readLine()
                    for panel in solarpanels {
                        if panel.getModel() == solarModel{
                            p += 1
                            spacecraft.addPanel(panel: panel)
                            print("Successfully attached \(solarModel!) to \(model!)")
                        }
                    }
                    if p == 0{
                        print("Failed to find a Solar Panel with name \(solarModel!)...\nWould you like to create a panel of modal \(solarModel!)?(Y/N)")
                        let ans = readLine()?.lowercased()
                        if ans == "y"{
                            solarpanels.append(spacecraft.addPanel(solarModel!))
                            print("Success!")
                        }
                        else if ans == "n"{
                            print("As you wish")
                        }
                        else{
                            print("Failed to create...")
                        }
                    }
                }
            }
            if s == 0{
                print("Failed to find Spacecraft \(model!)...")
            }
            
        case 8:
            var p = 0
            print("Enter name of the person: ")
            let name = readLine()
            for person in people {
                if person.getName() == name{
                    p += 1
                    print("Enter state: ")
                    let state = readLine()
                    if state == "awake" || state == "on"{
                        person.wakeUp()
                    }
                    else if state == "asleep" || state == "ofа"{
                        person.sleep()
                    }
                    else{
                        print("Something went wrong")
                    }
                }
            }
            if p == 0{
                print("Failed to find a person with name \(name!)...)")
            }
        case 9:
            var s = 0
            var e = 0
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                if spacecraft.getModel() == model{
                    s += 1
                    if spacecraft.amountOfEngineers == 0 {
                        print("Failed to find an engineer on board of \(model!)")
                    }
                    else{
                        e += 1
                        for person in spacecraft.personnel!{
                            if person.proffesion == .engineer{
                                if e == 1{
                                    print("Enter state: ")
                                    let state = readLine()
                                    if state == "on"{
                                        let temp = Engineer(person: person)
                                        temp.setEngineState(engine: spacecraft.engine, state: .on)
                                        print("The engine is on")
                                    }
                                    else if state == "off"{
                                        let temp = Engineer(person: person)
                                        temp.setEngineState(engine: spacecraft.engine, state: .off)
                                        print("The engine is off")
                                    }
                                    else{
                                        print("Error : wrong state value")
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if s == 0{
                print("Failed to find Spacecraft \(model!)...")
            }
        case 10:
            var s = 0
            var e = 0
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                if spacecraft.getModel() == model{
                    s += 1
                    if spacecraft.amountOfScientists == 0 {
                        print("Failed to find an scientist on board of \(model!)")
                    }
                    else{
                        e += 1
                        for person in spacecraft.personnel!{
                            if person.proffesion == .scientist{
                                if e == 1{
                                    print("Enter state: ")
                                    let state = readLine()
                                    if state == "on"{
                                        let temp = Scientist(person: person)
                                        if let panels = spacecraft.solarPanels{
                                            for panel in panels{
                                                temp.setPanelState(panel: panel, state: .on)
                                                print("Panel \(panel.getModel()) is on")
                                            }
                                        }
                                    }
                                    else if state == "off"{
                                        let temp = Scientist(person: person)
                                        if let panels = spacecraft.solarPanels{
                                            for panel in panels{
                                                temp.setPanelState(panel: panel, state: .off)
                                                print("Panel \(panel.getModel()) is off")
                                            }
                                        }
                                    }
                                    else{
                                        print("Error : wrong state value")
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if s == 0{
                print("Failed to find Spacecraft \(model!)...")
            }
        case 11:
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                if spacecraft.getModel() == model{
                    spacecraft.captain?.startFlight(spacecraft: spacecraft)
                }
            }
        case 12:
            print("Warning: the captain must be either engineer or scientist!")
            var s = 0
            var p = 0
            print("Enter model of Spacecraft: ")
            let model = readLine()
            
            for spacecraft in spacecrafts{
                s += 1
                if spacecraft.getModel() == model{
                    print("Enter name of the person: ")
                    let name = readLine()
                    for person in people {
                        if person.getName() == name{
                            p += 1
                            if spacecraft.getModel() == person.occupation?.getModel(){
                                spacecraft.captain = person
                                print("Successfully chaged captain to \(name!)")
                            }
                            else{
                                print("Procces not authorised")
                            }
                        }
                    }
                    if p == 0{
                        print("Failed to find a person with name \(name!)...")
                        }
                    }
                }
            
            if s == 0{
                print("Failed to find Spacecraft \(model!)...")
            }
            
        case 13:
            dump(spacecrafts)
            print("Exiting the program")
            state = false
        default:
            state = false
        }
        print("\nWhat's next?\n")
    }
    else{
        print("Wrong input, try again")
    }
}

