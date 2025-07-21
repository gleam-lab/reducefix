#include <bits/stdc++.h>
using namespace std;

const int MAX_X = 1e6 + 10;

vector<bool> present(MAX_X, false); // Tracks if an element is present in the bag
set<int> unique_elements;           // Stores unique elements for fast counting

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            if (!present[x]) {
                unique_elements.insert(x);
            }
            present[x] = true;
        } else if (type == 2) {
            int x;
            cin >> x;

            if (present[x]) {
                unique_elements.erase(unique_elements.find(x));
            }
            present[x] = false;
        } else if (type == 3) {
            cout << unique_elements.size() << '\n';
        }
    }

    return 0;
}