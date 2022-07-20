#include <iostream>
#include <string_view>

class Parent {
    int value {};
    int v2 {};

    public:
        Parent(int x) : value{x} {}; 

        std::string_view getName() const { return "Parent"; } 
        int getValue() const { return value; }

        virtual int getValue2() const { return v2;};

        // The next few lines are relevant for overloading operator<<
        friend std::ostream& operator<< (std::ostream& out, const Parent& a) {
            return a.print(out);
        };

        virtual std::ostream& print(std::ostream& out) const {
            out << "base";
            return out;
        }
};



class Child: public Parent {
    int value {};
    int v2 {};

    public:
        Child(int x, int y) : Parent(x), v2{y} {};
        std::string_view getName() const { return "Child"; } 
        int getValue() const { return value; }

        // This is polymorphism - virtual functions
        virtual int getValue2() const { return v2; };
        // This acts the same way because of the override keyword
        //int getValue2() const override { return v2; };
        
};

int main() {

    Child bar {5, 7};
    Child& refBar{ bar };
    Child* pBar{ &bar };

    std::cout << pBar->getName() << '\n';
    std::cout << refBar.getName() << '\n';

    // THese are of type Parent so don't print out as you'd expect
    Parent& refFoo { bar };
    Parent* pFoo { &bar };

    std::cout << refFoo.getName() << '\n';
    std::cout << pFoo->getName() << '\n';

    // Even though the Parent has a getValue2() method, this refers to the
    // child, so uses the version of getValue2() furthest down the inheritance
    // chain as it's a virtual function.
    // Removing `virtual` from the function definitions in both classes would
    // result in the Parent.v2 getting printed out instead
    std::cout << refFoo.getValue2() << '\n';

    // THis should work now we've overloaded operator<<
    std::cout << bar << '\n';
}
