#include "musictrack.hpp"
#include <string>
#include <iostream> 

musictrack::musictrack(std::string artist, std::string title, double duration)
    : artist(artist), title(title), duration(duration){}

void musictrack::info() const{
    std::cout << "Song: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Duration: " << duration << " minutes" << std::endl;
}

void musictrack::play() const {
    std::cout << "Playing music: " << title << " by " << artist << std::endl;
}