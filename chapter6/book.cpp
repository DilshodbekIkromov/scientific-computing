#include "book.hpp"
#include <iostream>
#include <iomanip>

//  constructors
Book::Book() = default;
Book::Book(const std::string& title) : title_{title} {}

Book::Book(const std::string& title, const std::string& author)
    : title_{title}, author_{author} {}

Book::Book(const std::string& title, const std::string& author, int year, double price, int pages)
    : title_{title}, author_{author}, year_{year}, price_{price}, pages_{pages} {}

// now writing methods 
// title 
void Book::setTitle(const std::string& title) { title_ = title; }
std::string Book::getTitle() const { return title_; }
//author 
void Book::setAuthor(const std::string& author) { author_ = author; }
std::string Book::getAuthor() const { return author_; }
//years
void Book::setYear(int year) { year_ = year; }
int Book::getYear() const { return year_; }
//prices
void Book::setPrice(double price) { price_ = price; }
double Book::getPrice() const { return price_; }
//pages
void Book::setPages(int pages) { pages_ = pages; }
int Book::getPages() const { return pages_; }

// Utility methods
void Book::displayInfo() const {
    std::cout << "=== Book Information ===" << std::endl;
    std::cout << "Title: " << title_ << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "Year: " << year_ << std::endl;
    std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl;
    std::cout << "Pages: " << pages_ << std::endl;
    std::cout << "Price per page: $" << std::fixed << std::setprecision(3) << pricePerPage() << std::endl;
    std::cout << "Classic: " << (isClassic() ? "Yes" : "No") << std::endl;
    std::cout << "========================" << std::endl;
}

bool Book::isClassic() const {
    return (2025 - year_) >= 50;  // Books 50+ years old are classics
}

double Book::pricePerPage() const {
    if (pages_ == 0) return 0.0;
    return price_ / pages_;
}


