#include<iostream>
#include<string>
#include<vector>
struct Book{
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    int quantity = 1;
    bool is_loaned = false;
};
std::vector<Book*> book_vec;

void add_book();
void remove_book();
void display_book();
void ask_book_info(Book* book);
void print_book(Book* book);
void print_help();
void loan_book();

int main()
{
 std::string user_input = "";
 
 while(true){
    std::cout << std::endl;
    print_help();
    std::cout << "> ";
    std::cin >> user_input;
     if(user_input == "1"){
        add_book();
     }
     else if(user_input == "2"){
        display_book();
     }
     else if(user_input == "3"){
        remove_book();
        
     }
     else if(user_input == "4"){
        loan_book();
     }
     else if(user_input == "5"){
        print_help();
     }
     else if(user_input == "Q" or user_input == "q"){
        return EXIT_SUCCESS;
     }

 }


 return 0;
}

void add_book() {
    std::string isbn;
    std::cout << "Enter books ISBN: ";
    std::cin >> isbn;

    bool found = false;
    for (auto book : book_vec) {
        if (book->isbn == isbn) {
            book->quantity++;
            found = true;
            break;
        }
    }

    if (!found) {
        Book* book = new Book;
        book->isbn = isbn;
        std::cin.ignore();
        std::cout << "Enter book's title: ";
        std::getline(std::cin, book->title);
        std::cout << "Enter book's author: ";
        std::getline(std::cin, book->author);
        std::cout << "Enter book's publishing year: ";
        std::cin >> book->year;
        book_vec.push_back(book);
    }
}


void display_book() {
    std::string isbn;
    std::cout << "Enter book's ISBN that you want displayed: ";
    std::cin >> isbn;

    bool found = false;
    for (auto it = book_vec.begin(); it != book_vec.end(); ++it) {
        if ((*it)->isbn == isbn) {
            print_book(*it);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Couldn't find a book with matching ISBN." << std::endl;
    }
}

void remove_book() {
    std::string isbn;
    std::cout << "Enter book's ISBN that you want removed: ";
    std::cin >> isbn;

    bool found = false;
    for (auto it = book_vec.begin(); it != book_vec.end(); ++it) {
        if ((*it)->isbn == isbn) {
            delete *it;
            book_vec.erase(it);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Couldn't find a book with matching ISBN." << std::endl;
    }
}

void print_book(Book* book){
    std::cout << "Title: " << book->title << std::endl;
    std::cout << "Author: " << book->author << std::endl;
    std::cout << "Year: " << book->year << std::endl;
    std::cout << "Quantity: " << book->quantity << std::endl;
    std::cout << "Loaned: " << book->is_loaned << std::endl; 
}

void print_help(){
    std::cout << "Press 1 to add book." << std::endl;
    std::cout << "Press 2 to display book." << std::endl;
    std::cout << "Press 3 to delete book." << std::endl;
    std::cout << "Press 4 to loan a book." << std::endl;
    std::cout << "Press 5 for commands." << std::endl;
    std::cout << "Press Q to quit." << std::endl;
}
void loan_book() {
    std::string isbn;
    std::cout << "Enter book's ISBN that you want to loan: ";
    std::cin >> isbn;

    bool found = false;
    for (auto it = book_vec.begin(); it != book_vec.end(); ++it) {
        if ((*it)->isbn == isbn) {
            (*it)->is_loaned = true;  // Corrected line
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Couldn't find a book with matching ISBN." << std::endl;
    }
}

/*Exercise:  Book Management System

You have been tasked with developing a Book Management System
 for a library. The system should allow users to manage books in the library

Books in the library have the following information.
 Title, Author, ISBN, Year, Quantity. The information will be stored with
  proper data types.

There should be a function to display a book, add a book and 
remove a book, see if the book has been loaned or not*/