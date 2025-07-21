#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> distinctNumbers; // Use a set to store distinct numbers
    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) { // Add a number to the set
            int x;
            cin >> x;
            distinctNumbers.insert(x);
        } else if (type == 2) { // Remove a number from the set
            int x;
            cin >> x;
            distinctNumbers.erase(x);
        } else if (type == 3) { // Output the number of distinct integers
            cout << distinctNumbers.size() << endl;
        }
    }
    return 0;
}