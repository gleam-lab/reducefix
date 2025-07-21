#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> h;
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            h.insert(x);
        } else if (type == 2) {
            cin >> x;
            // Since the problem guarantees that the ball with integer x exists in the bag
            // h.erase(x) is guaranteed to work without throw an error
            h.erase(x);
        } else {
            cout << h.size() << endl;
        }
    }

    return 0;
}