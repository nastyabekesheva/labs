//
//  Engine.swift
//  Spacecraft
//
//  Created by Nastya Bekesheva on 08.04.2022.
//

import Foundation

class Engine{
    
    private let model: String
    var state: State
    
    enum State{
        case on, off
    }
    
    init(_ model: String){
        self.model = model
        self.state = .off
    }
    
}
