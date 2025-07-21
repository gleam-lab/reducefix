#include<bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;

    unordered_set<int> h; // Use unordered_set for O(1) average time complexity for insert and erase operations
    int type, x;
    while( q-- ) {
        cin >> type;
        if ( type == 1 ) {
            cin >> x;
            h.insert(x); // Insert the element into the set
        } else if ( type == 2 ) {
            cin >> x;
            h.erase(x); // Erase the element from the set
        } else {
            cout << h.size() << endl; // Print the size of the set
        }
    }

    return 0;
}