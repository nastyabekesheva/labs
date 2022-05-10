//
//  Book.swift
//  Library
//
//  Created by Nastya Bekesheva on 10.05.2022.
//

import Foundation

class Book{
    private var name = String()
    private var genre: Genre
    
    enum Genre: String, CaseIterable{
        case fiction = "fiction"
        case novel = "novel"
        case fanrasy = "fantasy"
        case prose = "prose"
        case non_nonfiction = "non-fiction"
        case detctive = "detective"
        case other = "other"
    }
    
    init(name: String){
        self.name = name
        self.genre = .other
    }
    
    init(name: String, genre: Genre){
        self.name = name
        self.genre = genre
    }
    
    func getName() -> String { return self.name }
    func getGenre() -> Genre { return self.genre }
}

extension Book: Equatable{
    
    public static func==(lhs: Book, rhs: Book) -> Bool { return lhs.name == rhs.name && lhs.genre == rhs.genre }
    
}
