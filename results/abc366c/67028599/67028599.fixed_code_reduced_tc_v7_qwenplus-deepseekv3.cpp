#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> count;
    set<int> distinct;
    int type, x;
    while(q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << '\n';
        }
    }

    return 0;
}