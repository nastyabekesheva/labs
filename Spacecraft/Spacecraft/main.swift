//
//  main.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

let captain = Engineer("Jack")
let engine = Engine("F32")
var spacecraft: Spacecraft? = Spacecraft(model: "X002", engine: engine, captain: captain, personnel: nil)
var person = spacecraft!.addPersonnel("Lily")
var scientist: Scientist? = Scientist("Tom")
let panel = SolarPanel("UO83")

scientist!.setPanelState(panel: panel, state: .on)
spacecraft!.addPanel(panel: panel)
spacecraft!.addPersonnel(person: scientist!)
captain.setEngineState(engine: engine, state: .on)

spacecraft!.startFlight()
dump(spacecraft)



