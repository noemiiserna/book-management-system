#include <iostream>
#include "Book.hpp"
#include "Person.hpp"
#include "library.hpp"
using namespace std;

int main() {
    Library library;

    // Create and add books to the library
    Book b1("Pride and Prejudice", "Jane Austen", true);
    Book b2("The Hobbit", "J.R.R. Tolkien", true);
    Book b3("Harry Potter and the Philosopher's Stone", "J.K. Rowling", true);

    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);

    // Create and add people to the library
    Person p1("Candela", "Lopez");
    Person p2("Gabriela", "Ruiz");
    Person p3("Rocio", "Perez");

    library.addPerson(p1);
    library.addPerson(p2);
    library.addPerson(p3);

    // Show all books
    cout << "\nInformation about the books in the library:\n";
    for (const Book &book : library.getBooks()) {
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
             << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
    }

    // Show all people
    cout << "\nInformation about the people in the library:\n";
    for (const Person &person : library.getPeople()) {
        cout << "Name: " << person.getName() << ", Surname: " << person.getSurname() << endl;
    }

    // Test reserving books
    cout << "\nAttempting to reserve books:\n";
    p1.reserveBook(*library.findBook("Harry Potter and the Philosopher's Stone"));
    p2.reserveBook(*library.findBook("The Hobbit"));
    p3.reserveBook(*library.findBook("Pride and Prejudice"));

    // Show updated book list after reservations
    cout << "\nInformation about the books after reservations:\n";
    for (const Book &book : library.getBooks()) {
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
             << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
    }

    // Test returning books
    cout << "\nAttempting to return books:\n";
    p1.returnBook(*library.findBook("Harry Potter and the Philosopher's Stone"));
    p2.returnBook(*library.findBook("The Hobbit"));
    p3.returnBook(*library.findBook("Pride and Prejudice"));

    // Show updated book list after returns
    cout << "\nInformation about the books after returns:\n";
    for (const Book &book : library.getBooks()) {
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
             << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
    }

    // Test finding a book that exists
    cout << "\nSearching for a book titled 'The Hobbit':\n";
    Book *foundBook = library.findBook("The Hobbit");
    if (foundBook) {
        cout << "Book found: Title: " << foundBook->getTitle() << ", Author: " << foundBook->getAuthor() << endl;
    } else {
        cout << "Book not found.\n";
    }

    // Test finding a book that does not exist
    cout << "\nSearching for a book titled 'Nonexistent Book':\n";
    foundBook = library.findBook("Nonexistent Book");
    if (foundBook) {
        cout << "Book found: Title: " << foundBook->getTitle() << ", Author: " << foundBook->getAuthor() << endl;
    } else {
        cout << "Book not found.\n";
    }

    // Test removing a book that exists
    cout << "\nRemoving the book 'Pride and Prejudice':\n";
    if (library.removeBook("Pride and Prejudice")) {
        cout << "Book successfully removed.\n";
    } else {
        cout << "Failed to remove the book.\n";
    }

    // Test removing a book that does not exist
    cout << "\nRemoving the book 'Nonexistent Book':\n";
    if (library.removeBook("Nonexistent Book")) {
        cout << "Book successfully removed.\n";
    } else {
        cout << "Failed to remove the book.\n";
    }

    // Show updated book list
    cout << "\nInformation about the books in the library after removal:\n";
    for (const Book &book : library.getBooks()) {
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
             << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
    }

    // Test adding a new book
    cout << "\nAdding a new book 'Brave New World':\n";
    Book b4("Brave New World", "Aldous Huxley", true);
    library.addBook(b4);

    return 0;
}
