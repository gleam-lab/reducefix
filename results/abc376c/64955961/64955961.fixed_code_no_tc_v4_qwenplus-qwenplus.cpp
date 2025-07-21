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

    // We need to find the minimum x such that all toys can be packed.
    // Strategy:
    // Try to fit largest toys into largest boxes.
    // If a toy cannot go in any box, we will put it in the extra box,
    // whose size must be at least this toy's size.
    ll required = 0;

    ll j = n - 2; // index for boxes (sorted descending)
    for (ll i = n - 1; i >= 0; --i) {
        if (j >= 0 && a[i] <= b[j]) {
            j--; // use this box
        } else {
            // This toy needs the new box
            required = max(required, a[i]);
        }
    }

    cout << required << endl;
}

int main() {
    solve();
}