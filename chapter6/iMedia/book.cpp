#include "book.hpp"
#include <iostream>

book::book(std::string title, std::string author, int page) 
    : title(title), author(author), page(page){}

void book::info() const {
    std::cout << "This is the name of book: " << title << std::endl;
    std::cout << "This is the author of book: " << author << std::endl;
    std::cout << "This is the page of book: " << page << std::endl;
}

void book::play() const {
    std::cout << "Reading the book: " << title << std::endl;
}