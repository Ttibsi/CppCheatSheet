#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    streampos beginning, end;
    ifstream myfile ("foo.txt", ios::binary);

    beginning = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();

    myfile.close();
    cout << "Size in bytes: " << (end-beginning) << endl;
}
