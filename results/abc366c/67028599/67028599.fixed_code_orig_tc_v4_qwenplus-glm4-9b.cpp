#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> h;  // Using set to store unique integers
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            h.insert(x);  // Insert x into the set
        } else if (type == 2) {
            cin >> x;
            h.erase(x);  // Remove x from the set
        } else {
            cout << h.size() << endl;  // Output the size of the set
        }
    }

    return 0;
}