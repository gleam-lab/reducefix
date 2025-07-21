#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> h;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            h.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            h.erase(x);
        } else {
            cout << h.size() << endl;
        }
    }

    return 0;
}