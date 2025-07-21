#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int Q; cin >> Q;
    multiset<int> bag;
    set<int> distinct;

    rep(i, Q) {
        int query_type; cin >> query_type;
        if (query_type == 1) {
            int x; cin >> x;
            bag.insert(x);
            distinct.insert(x);
        } else if (query_type == 2) {
            int x; cin >> x;
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
                if (bag.count(x) == 0) {
                    distinct.erase(x);
                }
            }
        } else if (query_type == 3) {
            cout << distinct.size() << endl;
        }
    }
    return 0;
}