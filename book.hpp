#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;
    string reservationName;

public:
    // Constructor
    Book(string t = "The NeverEnding Story", string a = "Michael Ende", bool d = true);

    // Getters
    string getTitle() const;
    string getAuthor() const;
    bool isAvailable() const;
    string getReservationName() const;

    // Setters
    void setAvailable(bool d);
    void setTitle(string t);
    void setAuthor(string a);
    void setReservationName(string n);
};

#endif // BOOK_HPP
