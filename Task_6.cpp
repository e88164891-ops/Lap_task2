#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    string filename = "grades.txt";
    string tempFilename = "temp.txt";

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating " << filename << endl;
        return 1;
    }

    cout << "Enter 5 integer grades:" << endl;
    for (int i = 0; i < 5; i++) {
        int grade;
        cin >> grade;
        outFile << grade << endl;
    }
    outFile.close();

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening " << filename << endl;
        return 1;
    }

    cout << "\nGrades in " << filename << ":" << endl;
    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
    }

    if (inFile.bad()) {
        cout << "Error reading " << filename << endl;
        inFile.close();
        return 1;
    }
    inFile.close();

    int gradeToDelete;
    cout << "\nEnter a grade to delete: ";
    cin >> gradeToDelete;

    ifstream readAgain(filename);
    ofstream tempFile(tempFilename);

    if (!readAgain || !tempFile) {
        cout << "Error opening files for deletion." << endl;
        return 1;
    }

    int currentGrade;
    bool deletedOnce = false;
    while (readAgain >> currentGrade) {
        if (currentGrade == gradeToDelete && !deletedOnce) {
            deletedOnce = true;
            continue;
        }
        tempFile << currentGrade << endl;
    }

    readAgain.close();
    tempFile.close();

    if (remove(filename.c_str()) != 0) {
        cout << "Error removing original file." << endl;
        return 1;
    }

    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        cout << "Error renaming temporary file." << endl;
        return 1;
    }

    cout << "File updated successfully." << endl;
    if (!deletedOnce) {
        cout << "Grade not found." << endl;
    }

    return 0;
}
