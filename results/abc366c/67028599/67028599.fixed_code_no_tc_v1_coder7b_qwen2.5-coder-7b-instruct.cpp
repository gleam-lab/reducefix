#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> h;
    while(q--) {
        int type, x;
        cin >> type;
        if(type == 1) {
            cin >> x;
            h.insert(x); // Corrected: insert operation should be outside the condition
        } else if(type == 2) {
            cin >> x;
            h.erase(h.find(x)); // Corrected: erase operation requires finding the element first
        } else {
            cout << h.size() << endl; // Corrected: size of set directly gives the count of unique elements
        }
    }
    return 0;
}