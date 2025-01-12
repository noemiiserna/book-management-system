#include "Person.hpp"

Person::Person(string n, string s) : name(n), surname(s) {}

string Person::getName() const {
    return name;
}
string Person::getSurname() const {
    return surname;
}

void Person::setName(string n) {
    name = n;
}
void Person::setSurname(string s) {
    surname = s;
}

void Person::reserveBook(Book &book) {
    // Check if the book is available
	if (book.isAvailable()) {
            // Make the reservation
            book.setAvailable(false);
            book.setReservationName(getName());
            cout << "Book '" << book.getTitle() << "' reserved by " << getName() << " " << getSurname() << endl;
        } else {
            cout << "The book '" << book.getTitle() << "' is not available for reservation." << endl;
        }
    }

void Person::returnBook(Book &book) {
    // Check if the book was reserved by this person
        if (!book.isAvailable() && book.getReservationName() == getName()) {
            book.setAvailable(true);
            cout << "Book '" << book.getTitle() << "' returned by " << getName() << " " << getSurname() << endl;
        } else {
            cout << "Cannot return the book '" << book.getTitle() << "'. It is not reserved by " << getName() << " " << getSurname() << endl;
        }
    }
