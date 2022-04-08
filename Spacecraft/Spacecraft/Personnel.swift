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
    
    func wakeUp(){
        self.state = .awake
    }
    
    func sleep(){
        self.state = .asleep
    }
    
    func getName() -> String{
        return self.name
    }
    
    deinit{
        print("ok")
        print(self.occupation)
        self.occupation?.amountOfScientists -= 1
    }
    
    
}
