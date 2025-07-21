#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<int> s;
    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else if (type == 3) {
            cout << s.size() << endl;
        }
    }

    return 0;
}