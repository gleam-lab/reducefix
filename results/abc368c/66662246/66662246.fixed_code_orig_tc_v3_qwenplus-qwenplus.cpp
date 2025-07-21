#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        ll low = 0, high = 3 * h + 5;
        while (low < high) {
            ll mid = (low + high) / 2;
            // Count how many 3-damage hits occur in 'mid' steps
            ll three_damage_count = mid / 3;
            ll total_damage = three_damage_count * 3 + (mid - three_damage_count) * 1;
            if (total_damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        ans += low;
    }

    cout << ans << endl;
}