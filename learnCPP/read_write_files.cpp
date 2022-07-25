#include <iostream>
#include <fstream>
#include <string>

int out() {
    // open in append mode
    std::ofstream file {"foo.txt", std::ios::app};

    // If we couldn't open the file, quit
    if (!file) {
        std::cerr << "No file to write to";
        return 1;
    }

    //write lines to file
    file << "This is line 1" << '\n';
    file << "This is line 2" << '\n';

    return 0;
} //the ofstream is only closed when it goes out of scope here

int in() {
    // Opening the file using .open()
    std::ifstream infile;
    infile.open("foo.txt");

    if (!infile) {
        std::cerr << "No file to read from";
        return 1;
    }

    while (infile) {
        std::string line;
        std::getline(infile, line);
        std::cout << line << '\n';
    }

    return 0;
} //the ifstream is only closed only goes out of scope here 

int main() {
    out();
    in();
} 
