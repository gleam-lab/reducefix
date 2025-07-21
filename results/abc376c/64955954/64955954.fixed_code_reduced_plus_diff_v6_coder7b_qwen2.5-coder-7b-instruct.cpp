#include <bits/stdc++.h>
using namespace std;

bool canPlaceAllToys(vector<int>& toys, vector<int>& boxes) {
    int n = toys.size();
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(boxes.begin(), boxes.end(), toys[i]);
        if (it == boxes.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n);
    for (int i = 0; i < n; i++) cin >> va[i];
    for (int i = 0; i < n - 1; i++) cin >> vb[i];

    if (canPlaceAllToys(va, vb)) {
        cout << *max_element(begin(vb), end(vb)) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}