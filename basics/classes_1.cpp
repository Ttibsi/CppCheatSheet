#include <iostream>
using namespace std;

class Animal {
    string name;
    int age;

    public:
        Animal(string, int); // Allow for constructor
        string sound;
        void speak();
        void set_values(string, int);
        string get_name();
};

// Constructor Method
Animal::Animal(string obj_name, int obj_age)
{
    name = obj_name;
    age = obj_age;
}

// Method
void Animal::speak() {
    cout << sound; 
}

void Animal::set_values(string obj_name, int obj_age)
{
    name = obj_name;
    age = obj_age;
}

string Animal::get_name()
{
    return name;

}

int main()
{
    Animal* dogptr; // pointer of type Animal too
    Animal dog("Sparkle", 4);
    cout << dog.get_name() << "\n";
    dog.set_values("Fido", 3);
    cout << dog.get_name() << "\n";
    dog.sound = "Woof";
    dog.speak();
}
