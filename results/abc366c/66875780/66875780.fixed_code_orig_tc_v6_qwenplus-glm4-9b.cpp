#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    set<int> bag;
    while (Q--) {
        int query;
        cin >> query;

        if (query == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (query == 2) {
            int x;
            cin >> x;
            bag.erase(x);
        } else {
            cout << bag.size() << '\n';
        }
    }

    return 0;
}