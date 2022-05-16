//
//  main.swift
//  Library
//
//  Created by Nastya Bekesheva on 09.05.2022.
//

import Foundation

func contains(what: [Person], who: String) -> Bool {
    var count = false
    for person in people{
        if person.getName() == who{
            count = true
        }
    }
    return count
}

var myLibrary = Library()
var people: [Person] = []
var readers: [Reader: String] = [:]
var librarians: [Librarian: String] = [:]


print(" 1. Sign up as Librarian\n 2. Sign in as Librarian\n 3. Sign up as Reader\n 4. Sign in as Reader\n 5. Exit")

var action = true

while action{
    let answer = Int(readLine()!)
    switch answer{
    case 1:
        print("Enter name:")
        let name = readLine()
        let count = contains(what: people, who: name!)
        if count{
            print("This user already exists")
        }
        else{
            print("Enter password:")
            let password = readLine()
            let librarian = Librarian(name: name!)
            people.append(librarian)
            librarians[librarian] = password
            print("Success!")
        }
    case 2:
        print("Enter name:")
        let name = readLine()
        let count = contains(what: people, who: name!)
        if count{
            print("Enter password:")
            let enteredPassword = readLine()
            for (librarian, password) in librarians{
                if librarian.getName() == name{
                    if password == enteredPassword{
                        print("Succes!\n 1. Add book\n 2. Delete book\n 3. Sign out")
                        var newAction = true
                        while newAction{
                            let newAnswer = Int(readLine()!)
                            switch newAnswer{
                            case 1:
                                print("Enter name of book: ")
                                let bookName = readLine()
                                print("Enter book's genre: ")
                                let bookGenre = readLine()
                                var genre = Book.Genre.other
                                for genres in Book.Genre.allCases{
                                    if genres.rawValue == bookGenre{
                                        genre = genres
                                    }
                                }
                                librarian.addBook(book: Book(name: bookName!, genre: genre), to: myLibrary)
                                print("Success!")
                            case 2:
                                print("Enter name of book: ")
                                let bookName = readLine()
                                print("Enter book's genre: ")
                                let bookGenre = readLine()
                                var genre = Book.Genre.other
                                for genres in Book.Genre.allCases{
                                    if genres.rawValue == bookGenre{
                                        genre = genres
                                    }
                                }
                                let myBook = Book(name: bookName!, genre: genre)
                                if myLibrary.readingRoom.contains(book: myBook){
                                    librarian.deleteBook(book: myBook, from: myLibrary)
                                    print("Success!")
                                }
                                else{
                                    print("This book was not in the library")
                                }
                            case 3:
                                print("Successfully signed out!")
                                newAction = false
                            case .none:
                                newAction = false
                            case .some(_):
                                newAction = false
                            }
                        }
                    }
                    else{
                        print("Wrong password")
                    }
                }
            }
        }
        else{
            print("This user doesn't exist")
        }
    case 3:
        print("Enter name:")
        let name = readLine()
        let count = contains(what: people, who: name!)
        if count{
            print("This user already exists")
        }
        else{
            print("Enter password:")
            let password = readLine()
            let reader = Reader(name: name!)
            people.append(reader)
            readers[reader] = password
            print("Success!")
        }
    case 4:
        print("Enter name:")
        let name = readLine()
        let count = contains(what: people, who: name!)
        if count{
            print("Enter password:")
            let enteredPassword = readLine()
            for (reader, password) in readers{
                if reader.getName() == name{
                    if password == enteredPassword{
                        print("Succes!\n 1. Get book\n 2. Return book\n 3. List available books\n 4. Sign out")
                        var newAction = true
                        while newAction{
                            let newAnswer = Int(readLine()!)
                            switch newAnswer{
                            case 1:
                                print("Enter name of book: ")
                                let bookName = readLine()
                                print("Enter book's genre: ")
                                let bookGenre = readLine()
                                var genre = Book.Genre.other
                                for genres in Book.Genre.allCases{
                                    if genres.rawValue == bookGenre{
                                        genre = genres
                                    }
                                }
                                let myBook = reader.getBook(book: Book(name: bookName!, genre: genre), from: myLibrary)
                                print("Success!")
                            case 2:
                                print("Enter name of book: ")
                                let bookName = readLine()
                                print("Enter book's genre: ")
                                let bookGenre = readLine()
                                var genre = Book.Genre.other
                                for genres in Book.Genre.allCases{
                                    if genres.rawValue == bookGenre{
                                        genre = genres
                                    }
                                }
                                reader.returnBook(book: Book(name: bookName!, genre: genre), to: myLibrary)
                            case 3:
                                myLibrary.sortByGenre()
                            case 4:
                                print("Successfully signed out!")
                                newAction = false
                            case .none:
                                newAction = false
                            case .some(_):
                                newAction = false
                            }
                        }
                    }
                    else{
                        print("Wrong password")
                    }
                }
            }
        }
        else{
            print("This user doesn't exist")
        }
    case 5:
        print("Exiting the program")
        action = false
    case .none:
        action = false
    case .some(_):
        action = false
    }
}
