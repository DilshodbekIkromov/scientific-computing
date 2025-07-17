#ifndef MUSICTRACK_HPP
#define MUSICTRACK_HPP
#include "imedia.hpp"
#include <string>



class musictrack: public imedia
{
private:
    std::string artist;
    std::string title;
    double duration;
public:
    musictrack(std::string artist, std::string title, double duration);
    void info() const override;
    void play() const override;
};
#endif
