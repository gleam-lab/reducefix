#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;
    while(q--) {
        int type, x;
        cin >> type;
        if(type == 1) {
            cin >> x;
            s.insert(x); // Inserting element into the set
        } else if(type == 2) {
            cin >> x;
            s.erase(s.find(x)); // Removing element from the set if found
        } else if(type == 3) {
            cout << s.size() << endl; // Printing the size of the set
        }
    }
    return 0;
}