#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Calculate how many attacks are needed to reduce health h to 0 or less,
// given that the attack cycle starts at time t.
ll calc_attacks(ll t, ll h) {
    // We'll use binary search to find the minimum number of attacks T needed
    auto is_enough = [&](ll T) {
        ll damage = 0;
        for (ll i = 0; i < T; ++i) {
            t++;
            if (t % 3 == 0)
                damage += 3;
            else
                damage++;
            if (damage >= h)
                return true;
        }
        return damage >= h;
    };

    ll low = 0, high = 2e5; // Safe upper bound
    while (low < high) {
        ll mid = (low + high) / 2;
        ll temp_t = t;
        ll damage = 0;
        for (ll i = 0; i < mid; ++i) {
            temp_t++;
            if (temp_t % 3 == 0)
                damage += 3;
            else
                damage++;
            if (damage >= h)
                break;
        }
        if (damage >= h)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i)
        cin >> H[i];

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        if (H[i] > 0)
            T += calc_attacks(T, H[i]);
    }

    cout << T << endl;
    return 0;
}