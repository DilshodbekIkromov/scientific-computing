#include "audiobook.hpp"
#include <iostream>

audiobook::audiobook(std::string title, std::string author, int page, double duration)
    : book(title, author, page), duration(duration){}

void audiobook::info() const{
    std::cout << "AudioBook Title: " << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Pages: " << getPage() << std::endl;
    std::cout << "Duration: " << duration << " hours" << std::endl;
}

void audiobook::play() const{
    std::cout << "Playing audiobook: " << getTitle() << std::endl;
}

