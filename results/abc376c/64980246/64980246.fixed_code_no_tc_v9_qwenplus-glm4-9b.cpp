#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    // Pair up toys and boxes
    vector<pair<int, int>> toys_and_boxes(n);
    for (int i = 0; i < n; ++i) toys_and_boxes[i] = {a[i], i};
    for (int i = 0; i < n - 1; ++i) toys_and_boxes[i + 1] = {b[i], n + i};

    // Sort toys and boxes by size
    sort(toys_and_boxes.begin(), toys_and_boxes.end());

    // Check if all toys can fit into the boxes
    for (int i = 0; i < n; ++i) {
        if (toys_and_boxes[i].first > toys_and_boxes[i].second) {
            // Calculate the minimum box size needed
            cout << toys_and_boxes[i].second + 1 << endl;
            return;
        }
    }

    // If all toys fit into the boxes, the minimum box size is 1
    cout << 1 << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}