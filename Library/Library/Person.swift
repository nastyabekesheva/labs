//
//  Person.swift
//  Library
//
//  Created by Nastya Bekesheva on 10.05.2022.
//

import Foundation

class Person: Hashable{
    
    private var name = String()
    
    init() {}
    
    init(name: String) { self.name = name }
    
    func getName() -> String { return self.name }
    
    func hash(into hasher: inout Hasher) {
        hasher.combine(name)
    }
    
    static func == (lhs: Person, rhs: Person) -> Bool { return lhs.name == rhs.name }
}
