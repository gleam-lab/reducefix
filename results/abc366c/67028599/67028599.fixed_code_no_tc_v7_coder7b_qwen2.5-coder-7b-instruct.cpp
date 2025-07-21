#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_set<int> h; // Using unordered_set for faster insertions and deletions
    while(q--) {
        int type, x;
        cin >> type;
        if(type == 1) {
            cin >> x;
            h.insert(x); // Inserting element into the set
        } else if(type == 2) {
            cin >> x;
            h.erase(h.find(x)); // Removing element from the set
        } else {
            cout << h.size() << endl; // Printing the size of the set
        }
    }
    return 0;
}