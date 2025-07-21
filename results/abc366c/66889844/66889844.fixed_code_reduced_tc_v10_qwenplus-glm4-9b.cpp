#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> bag;
    while (Q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (queryType == 2) {
            int x;
            cin >> x;
            bag.erase(x);
        } else if (queryType == 3) {
            cout << bag.size() << endl;
        }
    }

    return 0;
}