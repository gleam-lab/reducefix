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

    multiset<ll> ms(b.begin(), b.end());

    ll need = -1;

    // Try to match largest toys with boxes
    for (ll i = n - 1; i >= 0; --i) {
        auto it = ms.lower_bound(a[i]);
        if (it != ms.end()) {
            ms.erase(it); // use this box
        } else {
            // This toy needs the additional box
            if (need == -1) {
                need = a[i];
            } else {
                // Already one toy needed new box, can't do it
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << need << endl;
}

int main() {
    solve();
}