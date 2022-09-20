//
//  Librarian.swift
//  Library
//
//  Created by Nastya Bekesheva on 10.05.2022.
//

import Foundation

class Librarian: Person{
    
    override init() { super.init() }
    
    override init(name: String) { super.init(name: name) }
    
    func addBook(book: Book, to library: Library){
        
        if library.find_book(book: book) != nil{
            print("Book \(book.getName()) already in library \(library.getName())")
        }
        else{
            library.readingRoom.storage.append(book)
            print("Book \(book.getName()) added to library \(library.getName())")
        }
        
    }
    
    func deleteBook(book: Book, from library: Library){
        
        if let bookIndex = library.find_book(book: book){
            library.readingRoom.storage.remove(at: bookIndex)
            print("Book \(book.getName()) deleted from library \(library.getName())")
        }
        else{
            print("Cannot find book \(book.getName()) in library \(library.getName())")
        }
            
    }
    
}
