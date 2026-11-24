#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int count;
    cout << "How many persons do you want to add? ";
    cin >> count;

    ofstream outFile("persons.txt");
    if (!outFile) {
        cerr << "Error opening persons.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        Person p;
        cout << "Person " << (i + 1) << " name: ";
        cin >> p.name;
        cout << "Person " << (i + 1) << " age: ";
        cin >> p.age;

        outFile << p.name << " " << p.age << "\n";
    }
    outFile.close();

    ifstream inFile("persons.txt");
    if (!inFile) {
        cerr << "Error reading persons.txt!" << endl;
        return 1;
    }

    vector<Person> people;
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        people.push_back(temp);
    }
    inFile.close();

    if (people.empty()) {
        cout << "No person records found.\n";
        return 0;
    }

    Person youngest = people[0];
    Person oldest = people[0];

    for (size_t i = 1; i < people.size(); ++i) {
        if (people[i].age < youngest.age) {
            youngest = people[i];
        }
        if (people[i].age > oldest.age) {
            oldest = people[i];
        }
    }

    ofstream resFile("results.txt");
    if (!resFile) {
        cerr << "Error creating results.txt!" << endl;
        return 1;
    }

    resFile << "Youngest Person: " << youngest.name << " (" << youngest.age << ")\n";
    resFile << "Oldest Person: " << oldest.name << " (" << oldest.age << ")\n";
    resFile.close();

    cout << "Youngest: " << youngest.name << " (" << youngest.age << ")\n";
    cout << "Oldest: " << oldest.name << " (" << oldest.age << ")\n";
    cout << "Results saved to results.txt.\n";

    return 0;
}
