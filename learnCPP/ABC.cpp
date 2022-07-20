#include <iostream>
#include <string>

// simple example of an Interface class
class IError {
    public:
        // Any class inheriting from IError must implement all methods itself
        virtual std::string printError(const std::string& errorMsg) = 0;

        // Just in case, destructor
        virtual ~IError() {};
};

// This counts as an abstract base class because of speak()
class Animal {
    protected:
        std::string name {};
        
        // protected constructor to stop Animal objects being created
        // but still allow for child classes to instantiate this class
        Animal(const std::string& foo) : name(foo) {};

    public:
        std::string getName() const { return name; }

        // This is a pure virtual method
        virtual const char* speak() const = 0;

        // Public and virtual destructor
        virtual ~Animal() = default;
};

class Cow : public Animal {
    public:
        Cow(const std::string& foo) : Animal(foo) {};

        // This overrides the base method in Animal
        // This is enforced by the compiler because Animal::speak() has no body
        const char* speak() const override { return "Moo"; }
};

int main() {
    Cow cow("Billy");
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    // pure virtual functions can be called with a pointer as well
    Animal& cowPtr{ cow };
    std::cout << cowPtr.speak(); // prints "moo"
}
