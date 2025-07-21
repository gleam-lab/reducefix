#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We simulate the process using a queue to represent attacks
    // Each enemy must be attacked until its health drops to 0 or less
    // Since only the frontmost enemy can be attacked at any time,
    // we need to manage when enemies drop out of the front.

    // We use a priority queue to simulate attacks efficiently.
    // The idea is to determine how many full cycles of attack patterns are possible,
    // and then simulate the remaining steps.

    // Binary search approach to find minimum T

    auto can_clear = [&](ll time) {
        vector<ll> h = H;
        ll idx = 0;
        for (ll t = 1; t <= time && idx < n; ++t) {
            if (h[idx] == 0) idx++;
            if (idx >= n) break;
            ll damage = (t % 3 == 0) ? 3 : 1;
            h[idx] -= damage;
        }
        return idx == n || all_of(h.begin(), h.end(), [](ll x){ return x <= 0; });
    };

    ll low = 0, high = 4e18;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (can_clear(mid)) high = mid;
        else low = mid + 1;
    }

    cout << low << endl;

    return 0;
}