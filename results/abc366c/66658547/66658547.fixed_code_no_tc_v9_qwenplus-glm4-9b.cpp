#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int q; cin >> q;
    unordered_set<int> bag;

    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int t; cin >> t;
            bag.insert(t);
        } else if (x == 2) {
            int t; cin >> t;
            bag.erase(t);
        } else if (x == 3) {
            cout << bag.size() << "\n";
        }
    }

    return 0;
}