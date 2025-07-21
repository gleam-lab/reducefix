#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> counts;
    set<int> distinct;
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (counts[x]++ == 0) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            if (--counts[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << '\n';
        }
    }

    return 0;
}