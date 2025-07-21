#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<int> bag;
    int q; cin >> q;
    vector<int> results;
    results.reserve(q);  // Reserve space to avoid reallocations

    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int value; cin >> value;
            bag.insert(value);
        } else if (x == 2) {
            int value; cin >> value;
            bag.erase(value);
        } else if (x == 3) {
            results.push_back(bag.size());
        }
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}