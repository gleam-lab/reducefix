#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    multiset<ll> ms;
    for (ll x : b) ms.insert(x);

    for (int i = n - 1; i >= 0; --i) {
        auto it = ms.lower_bound(a[i]);
        if (it != ms.end()) {
            ms.erase(it);
        } else {
            cout << a[i] << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}