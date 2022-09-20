//
//  Reader.swift
//  Library
//
//  Created by Nastya Bekesheva on 10.05.2022.
//

import Foundation

class Reader: Person{
    
    var ownedBooks: [Book] = []
    
    override init() { super.init() }
    
    override init(name: String) { super.init(name: name) }
    
    func getBook(book: Book, from library: Library) -> Book?{
        
        if let bookIndex = library.find_book(book: book){
            self.ownedBooks.append(book)
            library.readingRoom.storage.remove(at: bookIndex)
            return book
        }
        else{
            print("Cannot find book \(book.getName()) in library \(library.getName())")
            return nil
        }
        
    }
    
    func returnBook(book: Book, to library: Library){
        
        if let bookIndex = ownedBooks.firstIndex(of: book){
            library.readingRoom.storage.append(book)
            ownedBooks.remove(at: bookIndex)
            print("Book returned")
        }
        else{
            print("You don't own book \(book.getName())")
        }
        
    }
    
}
