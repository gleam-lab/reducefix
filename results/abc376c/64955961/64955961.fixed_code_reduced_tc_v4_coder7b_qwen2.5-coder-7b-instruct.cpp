#include<bits/stdc++.h>
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

    ll ans = -1;
    for (ll i = n - 1; i >= 0; --i) {
        bool valid = true;
        for (ll j = 0; j < n - 1 && valid; ++j) {
            if (a[i] < b[j]) {
                valid = false;
            } else {
                b[j] = -1; // Mark this box as used
            }
        }
        if (valid) {
            ans = a[i];
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}