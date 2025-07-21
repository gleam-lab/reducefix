#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    // Sort toy sizes in descending order to prioritize larger toys
    sort(a.begin(), a.end(), greater<int>());
    // Sort box sizes in descending order to prioritize larger boxes
    sort(b.begin(), b.end(), greater<int>());

    // We need to find the minimum box size x that can be used
    // such that all toys can be placed in one of the boxes
    // (existing boxes or the newly purchased box of size x).

    // The smallest box size must be at least as large as the largest toy,
    // so we initialize x with the size of the largest toy.
    int x = a[0];

    // Check if all toys can fit into existing boxes
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i]) {
            // If the i-th largest toy is larger than the i-th largest box,
            // there is a gap, and we can potentially use a smaller box.
            // However, we need to ensure that there is at least one box
            // that can fit the i-th largest toy, which is a[i].
            x = min(x, a[i]);
        }
    }

    // If x was never updated, it means all toys fit into the existing boxes
    if (x == a[0]) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}