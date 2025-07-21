#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset<int> ms;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n - 1 && b[j] < a[i]) {
            ms.insert(b[j]);
            ++j;
        }
        if (j < n - 1) {
            ++j; // Use this box for current toy
        } else if (!ms.empty()) {
            ms.erase(ms.begin()); // Use the smallest available box
        } else {
            cout << -1 << endl;
            return;
        }
    }

    // The required x is the minimum unused box size that can fit the largest toy
    // All toys have been matched except possibly one left in 'a'
    // Find the smallest unused box to place the remaining toy
    int max_toy = *max_element(a.begin(), a.end());
    int res = max_toy;

    // Check all elements in b not used yet
    while (j < n - 1) {
        res = min(res, b[j++]);
    }

    // Also check boxes stored in multiset
    if (!ms.empty()) {
        res = min(res, *ms.begin());
    }

    cout << res << endl;
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