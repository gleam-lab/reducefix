#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> s;
    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            s.insert(x); // Insert element into the set
        } else if (type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x)); // Erase element from the set if present
        } else if (type == 3) {
            cout << s.size() << endl; // Output the number of unique elements
        }
    }
    return 0;
}