#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> bag;

    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1) {  // Add x to the bag
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {  // Remove x from the bag
            cin >> x;
            bag.erase(x);
        } else if (type == 3) {  // Output the number of unique integers in the bag
            cout << bag.size() << endl;
        }
    }

    return 0;
}