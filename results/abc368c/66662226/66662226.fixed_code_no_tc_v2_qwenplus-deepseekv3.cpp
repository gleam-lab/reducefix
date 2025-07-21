#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = h * 2; // Upper bound can be large to cover all possibilities
    ll t = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 3 + (mid % 3);
        if (damage >= h) {
            t = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    ll current_time = 0;
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        // The attacks on this enemy start at current_time + 1
        // We need to find t such that sum of damages over t attacks is >= h
        // Damage is (t / 3) * 3 + (t % 3) ?
        // Or more accurately, sum_{k=1 to t} (k % 3 == 0 ? 3 : 1)
        // Which is: (t / 3) * 3 + (t % 3) * 1
        // Or: t + 2 * (t / 3)
        ll low = 0, high = h * 2;
        ll t = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = mid + 2 * (mid / 3);
            if (damage >= h) {
                t = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans += t;
        current_time += t;
    }
    cout << ans << endl;
    return 0;
}