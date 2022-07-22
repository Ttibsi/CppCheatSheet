#include <iostream>
#include <map>
#include <string>

int main() {
    // A map is a python dict, although a multimap is called a dictionary
    // instead. A multimap allows for non-unique keys in the KV pair

    std::map<int, std::string> myDict;
    myDict.insert(std::make_pair(1, "foo"));
    myDict.insert(std::make_pair(2, "bar"));
    myDict.insert(std::make_pair(3, "baz"));
    myDict.insert(std::make_pair(4, "waz"));

    auto iter = myDict.cbegin();
    while (iter != myDict.cend()) {
        std::cout << iter->first << ' ' << iter->second << '\n';
        ++iter;
    }
}
