#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> bag;
    
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            bag.erase(x);
        } else if (type == 3) {
            cout << bag.size() << endl;
        }
    }
    
    return 0;
}