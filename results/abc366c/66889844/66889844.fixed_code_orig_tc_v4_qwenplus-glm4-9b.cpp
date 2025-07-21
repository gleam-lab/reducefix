#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C and C++ I/O
    cin.tie(NULL); // Untie cin and cout so they can be used separately

    int Q; 
    cin >> Q;
    unordered_set<int> bag;

    for (int i = 0; i < Q; ++i) {
        int x; cin >> x;
        if (x == 3) {
            cout << bag.size() << '\n';
        } else {
            int y; cin >> y;
            if (x == 1) {
                bag.insert(y);
            } else if (x == 2) {
                bag.erase(y);
            }
        }
    }

    return 0;
}