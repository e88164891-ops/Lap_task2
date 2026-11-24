#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main() {
    ifstream inFile("fruit.txt");
    if (!inFile) {
        cerr << "Error opening fruit.txt for reading!" << endl;
        return 1;
    }
 
    string line;
    cout << "--- Fruit List ---\n";
    while (getline(inFile, line)) {
        cout << line << "\n";
    }
    inFile.close();
 
    // Append "Fresh Fruits" to the same file
    ofstream outFile("fruit.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening fruit.txt for appending!" << endl;
        return 1;
    }
 
    outFile << "Fresh Fruits\n";
    outFile.close();
 
    cout << "Appended \"Fresh Fruits\" to fruit.txt.\n";
    return 0;
}
