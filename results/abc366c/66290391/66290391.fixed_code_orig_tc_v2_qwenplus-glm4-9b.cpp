#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_set<int> bag;

    while (q--) {
        int type, x;
        cin >> type;

        if (type == 1) {
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            cin >> x;
            bag.erase(x);
        } else if (type == 3) {
            cout << bag.size() << endl;
        }
    }

    return 0;
}