#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> bag;
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x); // Insert x into the set
        } else if (type == 2) {
            int x;
            cin >> x;
            bag.erase(x); // Remove x from the set
        } else if (type == 3) {
            cout << bag.size() << endl; // Output the size of the set
        }
    }
    
    return 0;
}