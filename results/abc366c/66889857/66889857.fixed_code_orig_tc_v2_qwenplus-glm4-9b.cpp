#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q; cin >> Q;
    set<int> a;
    
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            a.insert(x);
        } else if (op == 2) {
            int x; cin >> x;
            a.erase(x);
        } else {
            cout << a.size() << endl;
        }
    }
}