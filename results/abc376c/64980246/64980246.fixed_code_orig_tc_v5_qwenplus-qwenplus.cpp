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

    multiset<int> ms(b.begin(), b.end());

    int x = -1;
    for (int i = 0; i < n; ++i) {
        auto it = ms.lower_bound(a[i]);
        if (it != ms.end()) {
            ms.erase(it); // use this box for toy a[i]
        } else {
            // This toy cannot be placed in any existing box, so we must buy a box for it
            if (x == -1)
                x = a[i];
            else {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << x << endl;
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