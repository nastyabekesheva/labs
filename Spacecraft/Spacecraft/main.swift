//
//  main.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

let captain = Engineer("Jack")
var spacecraft = Spacecraft(model: "X002", engine: "SX2", captain: captain, personnel: nil)
var person = spacecraft.addPersonnel("Lily")
var scientist = Scientist("Tom")
let panel = SolarPanel("UO83")
let me = Personnel("Me")
scientist.setPanelState(panel: panel, state: .on)
spacecraft.addPanel(panel: panel)
spacecraft.addPersonnel(person: scientist)
captain.setEngineState(engine: spacecraft.engine, state: .on)


captain.startFlight(spacecraft: spacecraft)
//dump(spacecraft)



