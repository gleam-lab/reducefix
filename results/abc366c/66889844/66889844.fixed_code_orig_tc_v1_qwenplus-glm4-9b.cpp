#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    cin.ignore(); // Ignore the first newline character
    set<int> bag;
    int uniqueCount = 0;

    // Read the entire input as lines
    while (getline(cin, line)) {
        istringstream iss(line);
        int type;
        if (iss >> type) {
            if (type == 1) {
                int number;
                iss >> number;
                bag.insert(number);
                if (bag.size() > uniqueCount) {
                    uniqueCount++;
                }
            } else if (type == 2) {
                int number;
                iss >> number;
                bag.erase(number);
                if (bag.size() < uniqueCount) {
                    uniqueCount--;
                }
            } else if (type == 3) {
                cout << uniqueCount << endl;
            }
        }
    }

    return 0;
}