#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> bag;
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            cin >> x;
            bag.erase(x);
        } else {
            cout << bag.size() << endl;
        }
    }

    return 0;
}