#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main() {
    string fullName, id, grade;
 
    cout << "Enter Full Name: ";
    getline(cin, fullName);
 
    cout << "Enter ID: ";
    getline(cin, id);
 
    cout << "Enter Grade: ";
    getline(cin, grade);
 
    ofstream outFile("Student.txt");
    if (!outFile) {
        cerr << "Error creating Student.txt!" << endl;
        return 1;
    }
 
    outFile << "Full Name: " << fullName << "\n";
    outFile << "ID: " << id << "\n";
    outFile << "Grade: " << grade << "\n";
 
    outFile.close();
    cout << "Student data written to Student.txt successfully.\n";
    return 0;
}
