#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

bool isPossible(const vector<ll>& H, ll T) {
    ll cnt3 = T / 3;
    ll cnt1 = T % 3;
    ll total_damage = cnt3 * 3 + cnt1 * 1;
    for (ll h : H) {
        ll needed3 = h / 3;
        if (h % 3 != 0) {
            needed3 += 1;
        }
        if (needed3 > cnt3) {
            ll remaining = h - cnt3 * 3;
            if (remaining > cnt1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll left = 0;
    ll right = 3 * *max_element(H.begin(), H.end());
    ll ans = right;
    
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cnt3 = mid / 3;
        ll cnt1 = mid % 3;
        bool possible = true;
        for (ll h : H) {
            ll needed3 = min(h / 3, cnt3);
            ll remaining = h - needed3 * 3;
            if (remaining > (mid - needed3 * 3)) {
                possible = false;
                break;
            }
        }
        if (possible) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
}