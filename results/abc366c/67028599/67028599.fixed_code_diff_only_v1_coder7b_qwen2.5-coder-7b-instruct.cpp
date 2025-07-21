#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_set<int> h; // Using unordered_set for faster operations
    int type, x;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            h.insert(x); // Insert element into set
        } else if(type == 2) {
            cin >> x;
            h.erase(x); // Erase element from set
        } else {
            cout << h.size() << endl; // Output the size of the set
        }
    }
    return 0;
}