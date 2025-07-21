#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int Q;
    cin >> Q;
    
    set<int> a; // Use set to store unique integers
    
    while (Q--) {
        int q;
        cin >> q;
        
        if (q == 1) {
            int x;
            cin >> x;
            a.insert(x); // Insert x into the set
        } else if (q == 2) {
            int x;
            cin >> x;
            a.erase(x); // Remove x from the set
        } else if (q == 3) {
            cout << a.size() << endl; // Output the size of the set
        }
    }
    
    return 0;
}