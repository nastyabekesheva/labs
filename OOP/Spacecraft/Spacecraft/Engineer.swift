//
//  Engineer.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Engineer: Personnel{
    
    override init(){super.init()}
    
    override init(_ name: String){
        super.init(name)
        proffesion = .engineer
    }
    
    init(person: Personnel){
        super.init(person.getName())
        proffesion = .scientist
    }
    
    func checkEngine(engine: Engine) -> Bool?{
        switch self.state{
        case .awake:
            switch engine.state{
            case .on:
                return true
            case .off:
                return false
            }
        case .asleep:
            print("Cannot check engine while sleeping")
            return nil
        }
    }
    
    func setEngineState(engine: Engine, state: Engine.State){
        engine.state = state
    }
    
}
