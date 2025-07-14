#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "book.hpp"

int main() {
    std::cout << "=== Book Management System ===" << std::endl << std::endl;
    
    // Different ways to create books
    std::cout << "1. Creating books with different constructors:" << std::endl;
    
    // Using default constructor
    Book book1;
    book1.setTitle("Learning C++");
    book1.setAuthor("John Doe");
    book1.setYear(2023);
    book1.setPrice(49.99);
    book1.setPages(450);
    
    // Using title-only constructor
    Book book2("The Great Gatsby");
    book2.setAuthor("F. Scott Fitzgerald");
    book2.setYear(1925);
    book2.setPrice(12.99);
    book2.setPages(180);
    
    // Using title and author constructor
    Book book3("To Kill a Mockingbird", "Harper Lee");
    book3.setYear(1960);
    book3.setPrice(14.99);
    book3.setPages(376);
    
    // Using full constructor
    Book book4("Clean Code", "Robert C. Martin", 2008, 59.99, 464);
    Book book5("Design Patterns", "Gang of Four", 1994, 69.99, 395);
    Book book6("1984", "George Orwell", 1949, 13.99, 328);
    
    // Store books in a vector
    std::vector<Book> library = {book1, book2, book3, book4, book5, book6};
    
    std::cout << std::endl << "2. Displaying all books:" << std::endl;
    for (size_t i = 0; i < library.size(); ++i) {
        std::cout << "Book " << (i + 1) << ":" << std::endl;
        library[i].displayInfo();
        std::cout << std::endl;
    }
    
    // Finding classics
    std::cout << "3. Classic books (50+ years old):" << std::endl;
    for (const auto& book : library) {
        if (book.isClassic()) {
            std::cout << "- " << book.getTitle() << " by " << book.getAuthor() 
                      << " (" << book.getYear() << ")" << std::endl;
        }
    }
    
    // Finding expensive books
    std::cout << std::endl << "4. Books over $50:" << std::endl;
    for (const auto& book : library) {
        if (book.getPrice() > 50.0) {
            std::cout << "- " << book.getTitle() << " - $" 
                      << std::fixed << std::setprecision(2) << book.getPrice() << std::endl;
        }
    }
    
    // Finding books by price per page
    std::cout << std::endl << "5. Most expensive per page:" << std::endl;
    Book mostExpensivePerPage = library[0];
    for (const auto& book : library) {
        if (book.pricePerPage() > mostExpensivePerPage.pricePerPage()) {
            mostExpensivePerPage = book;
        }
    }
    std::cout << "Book: " << mostExpensivePerPage.getTitle() << std::endl;
    std::cout << "Price per page: $" << std::fixed << std::setprecision(3) 
              << mostExpensivePerPage.pricePerPage() << std::endl;
    
    // Book statistics
    double totalPrice = 0;
    int totalPages = 0;
    for (const auto& book : library) {
        totalPrice += book.getPrice();
        totalPages += book.getPages();
    }
    
    std::cout << std::endl << "6. Library Statistics:" << std::endl;
    std::cout << "Total books: " << library.size() << std::endl;
    std::cout << "Total value: $" << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    std::cout << "Total pages: " << totalPages << std::endl;
    std::cout << "Average price: $" << std::fixed << std::setprecision(2) 
              << totalPrice / library.size() << std::endl;
    
    // Interactive example
    std::cout << std::endl << "7. Creating a custom book:" << std::endl;
    Book customBook;
    
    std::string title, author;
    int year, pages;
    double price;
    
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    customBook.setTitle(title);
    
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    customBook.setAuthor(author);
    
    std::cout << "Enter year: ";
    std::cin >> year;
    customBook.setYear(year);
    
    std::cout << "Enter price: ";
    std::cin >> price;
    customBook.setPrice(price);
    
    std::cout << "Enter pages: ";
    std::cin >> pages;
    customBook.setPages(pages);
    
    std::cout << std::endl << "Your book:" << std::endl;
    customBook.displayInfo();
    
    return 0;
}