#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int q;
    unordered_set<int> bag;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            bag.erase(x);
        } else if (type == 3) {
            cout << bag.size() << "\n";
        }
    }

    return 0;
}