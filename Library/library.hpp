//
//  library.hpp
//  Library
//
//  Created by Soo Yun Kim on 3/28/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#ifndef library_hpp
#define library_hpp

#include <stdio.h>
#include <iostream>

class Library {
    
public:
    friend std::ostream &operator<<(std::ostream &out, const Library &lib);
    
    // constructor
    Library(std::string name);
    
    // destructor
    ~Library();
    
    // Add a new book,
    // return true for success, false if book already in library
    bool AddBook(const std::string &name);

    // Remove a book,
    // return true for success, false if book not in library
    bool RemoveBook(const std::string &name);

    // List all books in library
    void ListAllBooks() const;

    // Return true if book in library, false otherwise
    bool IsInLibrary(const std::string &name) const;
    
private:
    // maximum value of the array
    static const int MAX = 100;
    // set the array as maximum value
    std::string arrBook[MAX];
    // number of books in the array
    int numberOfBooks;
    // Find index of the book in the array with name of book
    // return index number of the book from the array
    int findBook(const std::string& name) const;
};

#endif /* library_hpp */
