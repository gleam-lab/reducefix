#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;  // Use multiset to ensure unique elements
    int n = 0;        // Number of unique integers in the bag

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            m.insert(x);  // Insert unique element into the multiset
            if (m.size() > n) {
                n++;  // Only increment n when the size of the multiset exceeds the previous unique count
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            m.erase(m.find(x));  // Remove the unique element from the multiset
            if (m.size() < n) {
                n--;  // Only decrement n when the size of the multiset decreases
            }
        } else if (type == 3) {
            cout << n << endl;
        }
    }

    return 0;
}