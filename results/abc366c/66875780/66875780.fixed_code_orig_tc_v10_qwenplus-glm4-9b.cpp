#include <iostream>
#include <set>

using namespace std;

int main() {
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
        } else if (query == 3) {
            cout << bag.size() << endl;
        }
    }

    return 0;
}