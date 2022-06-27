#include <iostream>
#include <string>
using namespace std;

struct person {
    string name;
    int age;
    string favourite_colour;
};

// Function template
void printFaveColour (person p);

int main()
{
    string mystr;
    person user;

    cout << "What is your name? ";
    cin >> user.name;
    cout << "\nAge? ";
    cin >> user.age;
    cout << "\nFavourite colour? ";
    cin >> user.favourite_colour;

    printFaveColour(user);
}

void printFaveColour (person p)
{
    cout << "Your favourite colour is " << p.favourite_colour << " isn't it " << p.name << "?";
}


