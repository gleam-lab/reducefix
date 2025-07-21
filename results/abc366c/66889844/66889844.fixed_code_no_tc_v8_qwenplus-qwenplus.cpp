#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    multiset<int> bag;
    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            bag.erase(bag.find(x)); // Remove one occurrence of x
        } else if (type == 3) {
            // Count distinct integers in the multiset
            cout << bag.size() << endl;
        }
    }

    return 0;
}