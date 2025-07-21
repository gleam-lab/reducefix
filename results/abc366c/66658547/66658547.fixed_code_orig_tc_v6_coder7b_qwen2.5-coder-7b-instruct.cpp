#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<int> bag;
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            bag.insert(x);
        } else if (op == 2) {
            int x; cin >> x;
            bag.erase(bag.find(x));
        } else if (op == 3) {
            cout << bag.size() << '\n';
        }
    }

    return 0;
}