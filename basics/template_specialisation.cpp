#include <iostream>
using namespace std;

// General class template
template <class T>
class myContainer
{
    T elem;

    public:
        myContainer (T arg) {elem = arg;} // inline constructor
        T increase () {return ++elem;}
};

// Specialisation if we pass type char instead
template <>
class myContainer<char>
{
    char elem;

    public:
        myContainer (char arg) {elem = arg;}
        char uppercase()
        {
            if ((elem >= 'a') && (elem <= 'z')) {
                elem += 'A' - 'a';
                return elem;
            } else {
                return elem;
            }
        }
};

int main()
{
    myContainer<int> myint (7);
    myContainer<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
}
