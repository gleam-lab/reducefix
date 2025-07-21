#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    set<int> s;
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int x;
            cin >> x;
            s.insert(x); // Insert element into the set
        } else if(type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x)); // Erase element from the set
        } else {
            cout << s.size() << endl; // Output the number of unique elements in the set
        }
    }

    return 0;
}