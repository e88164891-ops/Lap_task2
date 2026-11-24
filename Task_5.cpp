#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening students.txt!" << endl;
        return 1;
    }

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        Student s;
        s.delim = '$';

        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(s.name, 20);

        cout << "Enter ID: ";
        cin >> s.id;

        cout << "Enter Grade: ";
        cin >> s.grade;

        outFile << s.name << ", " << s.id << ", " << s.grade << ", " << s.delim << "\n";

        cout << "Add another record? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    return 0;
}
