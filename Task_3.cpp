#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main() {
    // 1. Write initial sentence to welcome.txt
    ofstream outFile("welcome.txt");
    if (!outFile) {
        cerr << "Error creating welcome.txt!" << endl;
        return 1;
    }
    outFile << "Hello Everybody";
    outFile.close();
 
    // 2. Read contents and replace "body" with "one"
    ifstream inFile("welcome.txt");
    if (!inFile) {
        cerr << "Error reading welcome.txt!" << endl;
        return 1;
    }
    string text;
    getline(inFile, text);
    inFile.close();
 
    string target = "body";
    string replacement = "one";
    size_t pos = text.find(target);
    if (pos != string::npos) {
        text.replace(pos, target.length(), replacement);
    }
 
    // 3. Write updated result ("Hello Everyone") back to welcome.txt
    ofstream updatedFile("welcome.txt");
    if (!updatedFile) {
        cerr << "Error updating welcome.txt!" << endl;
        return 1;
    }
    updatedFile << text;
    updatedFile.close();
 
    cout << "Final result in welcome.txt: " << text << "\n";
    return 0;
}
