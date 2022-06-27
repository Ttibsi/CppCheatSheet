#include <iostream>
using namespace std;

class Animal {
    string name;
    int age;
    string sound;

    public:
        Animal() {};
        Animal(string n, int a, string s) : name(n), age(a), sound(s) {}

        void speak() {cout << sound << endl;}
};

class Dog: public Animal {
    string breed;
    public:
        // Constructor with parent constructor attached 
        Dog (string n, int a, string s, string b) : Animal(n, a, s), breed(b) {};
        string get_breed() {return breed;}
};

int main() {
    Dog fido("Fido", 2, "Woof", "sausage dog");
    cout << fido.get_breed() << endl;
    fido.speak();
}
