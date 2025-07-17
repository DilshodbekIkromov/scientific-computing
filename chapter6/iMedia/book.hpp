#ifndef BOOK_HPP
#define BOOK_HPP
#include "imedia.hpp"
#include <string>

class book: public imedia
{
private:
    std::string title;
    std::string author;
    int page;
public:
    book(std::string title, std::string author, int page);
    void info() const override;
    void play() const override;
    
    // Getter methods for derived classes
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPage() const { return page; }
};

#endif
