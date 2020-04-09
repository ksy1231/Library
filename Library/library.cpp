//
//  library.cpp
//  Library
//
//  Created by Soo Yun Kim on 3/28/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "library.hpp"

// friend function
std::ostream &operator<<(std::ostream &out, const Library &lib) {
    out << lib.arrBook << std::endl;
    return out;
}

// constructor
Library::Library(std::string name) {}

// destructor
Library::~Library() {}

// Add a new book,
// return true for success, false if book already in library
bool Library::AddBook(const std::string &name) {
    bool inLibrary = IsInLibrary(name);
    if (inLibrary) {
        return false;
    }
    arrBook[numberOfBooks] = name;
    numberOfBooks++;
    if (MAX < numberOfBooks) {
        return false;
    }
    return true;
}

// Remove a book,
// return true for success, false if book not in library
bool Library::RemoveBook(const std::string &name) {
    bool inLibrary = IsInLibrary(name);
    if (inLibrary) {
        int idx = findBook(name);
        numberOfBooks--;
        if (idx == numberOfBooks) {
            arrBook[idx] = "";
        } else {
            arrBook[idx] = arrBook[numberOfBooks];
        }
        return true;
    }
    return false;
}

// List all books in library
void Library::ListAllBooks() const {
    for (int i = 0; i < numberOfBooks; i++) {
        std::cout << arrBook[i] << std::endl;
    }
}

// Return true if book in library, false otherwise
bool Library::IsInLibrary(const std::string &name) const {
    for (int i = 0; i < numberOfBooks; i++) {
        if (name == arrBook[i]) {
            return true;
        }
    }
    return false;
}

// Find index of the book in the array with name of book
// return index number of the book from the array
int Library::findBook(const std::string& name) const {
    for (int i = 0; i < numberOfBooks; i++) {
        if (name == arrBook[i]) {
            return i;
        }
    }
    return 0;
}
