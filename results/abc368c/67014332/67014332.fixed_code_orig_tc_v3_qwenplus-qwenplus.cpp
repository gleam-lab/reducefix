#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }

    // The idea is to simulate attacks, keeping track of time T and when triple attacks occur
    ll t = 0, tri = 0;

    for (ll i = 0; i < n; ++i) {
        ll h = H[i];

        while (h > 0) {
            ++t;
            ++tri;

            if (tri == 3) {
                h -= 3;
                tri = 0;
            } else {
                h -= 1;
            }
        }
    }

    cout << t << "\n";
    return 0;
}