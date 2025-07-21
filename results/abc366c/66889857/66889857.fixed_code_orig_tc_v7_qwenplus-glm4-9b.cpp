#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> a; // Use set to manage unique integers

    while (Q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int x;
            cin >> x;
            a.insert(x); // Insert x into the set
        } else if (query_type == 2) {
            int x;
            cin >> x;
            a.erase(x); // Remove x from the set
        } else if (query_type == 3) {
            cout << a.size() << endl; // Output the size of the set
        }
    }

    return 0;
}