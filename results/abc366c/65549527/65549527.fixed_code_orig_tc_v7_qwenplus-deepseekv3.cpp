#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    multiset<int> bag;
    set<int> distinct;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
            distinct.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
                if (bag.count(x) == 0) {
                    distinct.erase(x);
                }
            }
        } else if (type == 3) {
            cout << distinct.size() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}