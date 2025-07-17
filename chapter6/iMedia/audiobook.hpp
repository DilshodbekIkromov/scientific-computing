#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP
#include "imedia.hpp"
#include "book.hpp"
#include <string>

class audiobook: public book
{
private:
    double duration;
public:
    audiobook( std::string title, std::string author, int page, double duration);
    void info() const override;
    void play() const override;

};



#endif 