#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    set<int> s;

    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            s.insert(x);
        } else if (type == 2) {
            cin >> x;
            s.erase(s.find(x));
        } else if (type == 3) {
            cout << s.size() << '\n';
        }
    }

    return 0;
}