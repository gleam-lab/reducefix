#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    unordered_set<int> h; // Using unordered_set for faster insertion and deletion
    int type, x;
    while(q--) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            h.insert(x); // Inserting element if not already present
        } else if(type == 2) {
            cin >> x;
            h.erase(h.find(x)); // Erasing element only if it exists
        } else {
            cout << h.size() << endl; // Printing the size of the set
        }
    }
    return 0;
}