#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book{
    private:
    std::string title_;
    std::string author_;
    int year_{0};
    double price_{0.0};
    int pages_{0};

    // in public we first build constructors (1.default 2.we desired) and then methods (getter setter etc)
    // all private and utility methods
    public:
    Book(); // default consturcterr
    Book(const std::string& title);
    Book(const std::string& title, const std::string& author);
    Book(const std::string& title, const std::string& author, int year, double price, int pages);

    // methods
    // title
    void setTitle(const std::string& title);
    std::string getTitle() const;

    // auther
    void setAuthor(const std::string& author);
    std::string getAuthor() const;

    // year
    void setYear(int year);
    int getYear() const;
    
    //price
    void setPrice(double price);
    double getPrice() const;
    
    // pages
    void setPages(int pages);
    int getPages() const;

    // utility methods
    void displayInfo() const;
    bool isClassic() const;
    double pricePerPage() const;
};

#endif
