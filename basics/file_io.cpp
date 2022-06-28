#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Create a file object
    ofstream myFile;

    // Open the file and save it to the object
    // We're setting it to append mode
    myFile.open("foo.txt", ios::app);

    // Write to a file
    myFile << "Write me to a file\n";
    myFile.close();
    ifstream myFile2;
    myFile2.open("foo.txt");

    // Output the text from the file
    string line;
    while (getline(myFile2, line))
    {
        // You cant use endl here as that'll flush the text buffer back
        // to the file
        cout << line << "\n";
    }

    // Close the file stream
    myFile2.close();
}
