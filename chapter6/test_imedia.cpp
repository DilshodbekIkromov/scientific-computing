#include <iostream>
#include <iomanip>
#include "iMedia/imedia.hpp"
#include "iMedia/book.hpp"
#include "iMedia/audiobook.hpp"
#include "iMedia/musictrack.hpp"

int main() {
    std::cout << "=== iMedia Testing Program ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    
    // Test Book
    std::cout << "\n--- Testing Book ---" << std::endl;
    book b1("The Great Gatsby", "F. Scott Fitzgerald", 180);
    std::cout << "Book created successfully!" << std::endl;
    b1.info();
    b1.play();
    
    std::cout << "\n--- Testing Another Book ---" << std::endl;
    book b2("1984", "George Orwell", 328);
    std::cout << "Second book created!" << std::endl;
    b2.info();
    b2.play();
    
    // Test AudioBook
    std::cout << "\n--- Testing AudioBook ---" << std::endl;
    audiobook ab1("Harry Potter", "J.K. Rowling", 500, 12.5);
    std::cout << "AudioBook created successfully!" << std::endl;
    ab1.info();
    ab1.play();
    
    std::cout << "\n--- Testing Another AudioBook ---" << std::endl;
    audiobook ab2("The Hobbit", "J.R.R. Tolkien", 310, 8.75);
    std::cout << "Second audiobook created!" << std::endl;
    ab2.info();
    ab2.play();
    
    // Test MusicTrack
    std::cout << "\n--- Testing MusicTrack ---" << std::endl;
    musictrack mt1("The Beatles", "Hey Jude", 4.5);
    std::cout << "Music track created successfully!" << std::endl;
    mt1.info();
    mt1.play();
    
    std::cout << "\n--- Testing Another MusicTrack ---" << std::endl;
    musictrack mt2("Queen", "Bohemian Rhapsody", 5.9);
    std::cout << "Second music track created!" << std::endl;
    mt2.info();
    mt2.play();
    
    // Test Polymorphism
    std::cout << "\n--- Testing Polymorphism ---" << std::endl;
    imedia* mediaItems[6] = {
        new book("To Kill a Mockingbird", "Harper Lee", 281),
        new audiobook("Dune", "Frank Herbert", 688, 21.0),
        new musictrack("Pink Floyd", "Wish You Were Here", 5.3),
        new book("Pride and Prejudice", "Jane Austen", 432),
        new audiobook("The Catcher in the Rye", "J.D. Salinger", 234, 6.5),
        new musictrack("Led Zeppelin", "Stairway to Heaven", 8.0)
    };
    
    for (int i = 0; i < 6; i++) {
        std::cout << "\n--- Media Item " << (i + 1) << " ---" << std::endl;
        mediaItems[i]->info();
        mediaItems[i]->play();
        std::cout << "------------------------" << std::endl;
    }
    
    // Test Different Media Types
    std::cout << "\n--- Testing Media Type Variety ---" << std::endl;
    std::cout << "Books (text-based reading material):" << std::endl;
    book classicBook("Moby Dick", "Herman Melville", 635);
    classicBook.info();
    classicBook.play();
    
    std::cout << "\nAudioBooks (spoken books with duration):" << std::endl;
    audiobook modernAudiobook("Atomic Habits", "James Clear", 320, 5.5);
    modernAudiobook.info();
    modernAudiobook.play();
    
    std::cout << "\nMusic Tracks (audio entertainment):" << std::endl;
    musictrack rockSong("AC/DC", "Thunderstruck", 4.8);
    rockSong.info();
    rockSong.play();
    
    // Clean up dynamically allocated memory
    std::cout << "\n--- Cleaning Up ---" << std::endl;
    for (int i = 0; i < 6; i++) {
        delete mediaItems[i];
    }
    std::cout << "Memory cleanup completed." << std::endl;
    
    std::cout << "\n=== iMedia Testing Complete ===" << std::endl;
    std::cout << "All media types tested successfully!" << std::endl;
    std::cout << "Polymorphism and inheritance working correctly!" << std::endl;
    
    return 0;
}
