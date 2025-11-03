#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    set<int> bag;
    
    while (Q--) {
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
            cout << bag.size() << '\n';
        }
    }
    
    return 0;
}