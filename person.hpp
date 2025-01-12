#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <vector>
#include "Book.hpp"
using namespace std;

class Person {
private:
    string name;
    string surname;

public:
    // Constructor
    Person(string n = "Noemi", string s = "Serna");

    // Getters
    string getName() const;
    string getSurname() const;

    // Setters
    void setName(string n);
    void setSurname(string s);

    void reserveBook(Book &book);
    void returnBook(Book &book);
};

#endif // PERSON_HPP