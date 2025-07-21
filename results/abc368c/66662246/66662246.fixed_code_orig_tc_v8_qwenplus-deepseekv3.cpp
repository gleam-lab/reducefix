#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 5 + (mid % 3 == 1 ? 1 : (mid % 3 == 2 ? 2 : 0));
        if (damage >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for (ll h : a) {
        ll low = 0, high = 2 * h;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll damage = (mid / 3) * 5 + (mid % 3 == 1 ? 1 : (mid % 3 == 2 ? 2 : 0));
            if (damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ans += low;
    }
    cout << ans << endl;
}