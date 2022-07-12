#include <iostream>
#include <string>

class Animal {
    int age;
    int weight;
    std::string name;

    static int animal_count;

    public:
        // Default constructor
        Animal() : age{0}, weight{0}, name{""} {}

        // Constructor with values
        // This can go on the next line indented as well
        Animal(int a, int w, std::string name): 
            age{a}, weight{w}, name{name} {}

        void printName(); 
        static int getCount();
};

// default value on a static attribute - even though it's private, this is fine
int Animal::animal_count = 1;

// This doesn't need the `static` keyword
int Animal::getCount() {
    return animal_count;
}

void Animal::printName() {
    std::cout << name << '\n';
}

int main() {
    Animal anim1; 
    Animal anim2(2,12, "Fido");
    anim2.printName();
}
