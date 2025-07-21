#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    set<int> s; // Using set to store unique elements
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int x;
            cin >> x;
            s.insert(x); // Inserting element into the set
        } 
        else if(type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x)); // Erasing element from the set if found
        } 
        else if(type == 3) {
            cout << s.size() << endl; // Printing the size of the set
        }
    }

    return 0;
}