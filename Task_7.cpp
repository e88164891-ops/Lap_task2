#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream input("students.txt");
    if (!input) {
        cout << "Error opening students.txt" << endl;
        return 1;
    }

    string name;
    vector<string> names;

    while (getline(input, name)) {
        if (!name.empty()) {
            names.push_back(name);
        }
    }

    input.close();

    sort(names.begin(), names.end());

    cout << "Names sorted successfully:" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    return 0;
}
