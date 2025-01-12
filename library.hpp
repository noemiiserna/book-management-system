// library.hpp
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include "Person.hpp"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;
    std::vector<Person> people;

public:
    // Constructor
    Library() = default;

    // Methods to manage books
    void addBook(const Book &book);
    bool removeBook(const std::string &title);
    Book* findBook(const std::string &title);

    // Methods to manage people
    void addPerson(const Person &person);

    // Getters
    const std::vector<Book>& getBooks() const;
    const std::vector<Person>& getPeople() const;
};

#endif