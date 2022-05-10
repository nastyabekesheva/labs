//
//  Library.swift
//  Library
//
//  Created by Nastya Bekesheva on 09.05.2022.
//

import Foundation

class Library{
    private var name = String()
    var readingRoom = ReadingRoom()
    
    init() {}
    
    init(name: String) { self.name = name }
    
    func getName() -> String { return name }
    
    func sortByGenre(){
        
        var list = [Book.Genre: String]()
        
        for genre in Book.Genre.allCases{
            list[genre] = String()
        }
        
        for book in readingRoom.storage{
            list[book.getGenre()]! += " |\(book.getName())| "
        }
        
        for genre in Book.Genre.allCases{
            print("\(genre.rawValue) : ")
            print(list[genre]!)
        }
    }
    
    func find_book(book: Book) -> Int?{
        
        if let ind = self.readingRoom.storage.firstIndex(of: book){
            return ind
        }
        
        return nil
    }
}
