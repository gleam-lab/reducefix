#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> a;
    set<int> removed;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (removed.count(x)) {
                removed.erase(x);
            }
            a.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            a.erase(x);
            removed.insert(x);
        } else if (type == 3) {
            // Output the number of active elements
            cout << a.size() << endl;
        }
    }

    return 0;
}