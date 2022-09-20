//
//  ReadingRoom.swift
//  Library
//
//  Created by Nastya Bekesheva on 10.05.2022.
//

import Foundation

class ReadingRoom{
    
    var storage: [Book] = []
    
    func contains(book: Book) -> Bool{
        
        for bookInStorage in self.storage{
            if book == bookInStorage{
                return true
            }
        }
        
        return false
    }
    
    func contains(book: String) -> Bool{
        
        for bookInStorage in self.storage{
            if book == bookInStorage.getName(){
                return true
            }
        }
        
        return false
    }
}
