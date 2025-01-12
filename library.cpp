#include "library.hpp"
#include <iostream>


// Add a book to the library
void Library::addBook(const Book &book) {
    books.push_back(book);
    std::cout << "Book '" << book.getTitle() << "' added to the library.\n";
}

// Remove a book by title
bool Library::removeBook(const std::string &title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            std::cout << "Book '" << title << "' removed from the library.\n";
            return true;
        }
    }
    std::cout << "Book '" << title << "' not found in the library.\n";
    return false;
}

// Find a book by title
Book* Library::findBook(const std::string &title) {
    for (auto &book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    std::cout << "Book '" << title << "' not found in the library.\n";
    return nullptr;
}

// Add a person to the library
void Library::addPerson(const Person &person) {
    people.push_back(person);
    std::cout << "Person '" << person.getName() << "' added to the library.\n";
}

// Get the list of books
const std::vector<Book>& Library::getBooks() const {
    return books;
}

// Get the list of people
const std::vector<Person>& Library::getPeople() const {
    return people;
}
