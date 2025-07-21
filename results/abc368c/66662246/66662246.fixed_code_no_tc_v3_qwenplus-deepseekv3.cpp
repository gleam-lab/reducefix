#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = h / 3;
    ll min_attacks = LLONG_MAX;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll remaining = h - 3 * mid;
        if (remaining < 0) {
            high = mid - 1;
            continue;
        }
        ll attacks = mid + remaining;
        if (3 * mid >= attacks) {
            min_attacks = min(min_attacks, 3 * mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return min_attacks;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    ll ans = 0;
    ll cumulative_attacks = 0;
    rep(i, n) {
        ll required_attacks = calculate_attacks(h[i]);
        if (cumulative_attacks >= required_attacks) {
            cumulative_attacks++;
        } else {
            cumulative_attacks = required_attacks;
        }
        ans = cumulative_attacks;
    }
    cout << ans << endl;
    return 0;
}