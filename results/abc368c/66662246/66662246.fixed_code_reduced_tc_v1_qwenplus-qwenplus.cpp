#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, n)
    {
        ll h = a[i];
        // For each enemy, determine how many triple attacks (t) and single attacks (s)
        // such that 3*t + s = h and s <= 2*t
        // We want to maximize number of triple attacks as they are more efficient
        // Let's find minimum t such that 3*t - h >= 0 and h <= 3*t + t = 4*t

        // Binary search for the minimum number of seconds needed for this enemy
        ll low = 0, high = h;
        while (low < high) {
            ll mid = (low + high) / 2;
            // In mid seconds, how many triple attacks can we do?
            // Triple attacks happen at T % 3 == 0 -> So roughly mid/3 times
            ll triple_attacks = mid / 3;
            // Total damage = triple_attacks * 3 + (mid - triple_attacks) * 1
            ll total_damage = triple_attacks * 3 + (mid - triple_attacks) * 1;
            if (total_damage >= h)
                high = mid;
            else
                low = mid + 1;
        }
        ans += low;
    }

    cout << ans << endl;
}