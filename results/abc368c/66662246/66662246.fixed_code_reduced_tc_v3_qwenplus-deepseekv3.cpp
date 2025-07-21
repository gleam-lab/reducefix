#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calculate_min_turns(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 5 + (mid % 3);
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
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll ans = 0;
    for (ll hi : h) {
        ll t = calculate_min_turns(hi);
        ans = max(ans, t);
    }
    cout << ans << endl;
}