#include <iostream>
#include <string>

struct Employee {
    int id {};
    int age {};
    std::string name = "";
};

int main() {
    Employee bob = {1, 32, "Bobby Singer"};
}
