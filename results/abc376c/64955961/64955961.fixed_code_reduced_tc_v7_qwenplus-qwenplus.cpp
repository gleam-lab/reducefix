#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Use binary search to find the minimum x
    ll left = 0, right = n - 1;
    ll ans = -1;

    // Try to match largest toys with largest available boxes
    multiset<ll> box_sizes;
    for (ll i = 0; i < n - 1; ++i) {
        box_sizes.insert(b[i]);
    }

    // We try to assign the largest toys to the largest boxes
    ll cnt = 0;
    for (ll i = n - 1; i >= 0; --i) {
        auto it = box_sizes.upper_bound(a[i]);
        if (it != box_sizes.begin()) {
            --it; // we found a suitable box
            box_sizes.erase(it);
        } else {
            cnt++;
            if (cnt > 1) {
                cout << -1 << endl;
                return;
            }
            ans = a[i];
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
}