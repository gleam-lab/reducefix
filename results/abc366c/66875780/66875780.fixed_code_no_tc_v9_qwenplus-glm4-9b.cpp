#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_set<int> bag;
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
            cout << bag.size() << '\n';
        }
    }

    return 0;
}