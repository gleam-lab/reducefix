#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_attacks(ll h, ll start_t) {
    ll low = 0;
    ll high = 2 * h; // A safe upper bound
    ll answer = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 5;
        ll remainder = mid % 3;
        if (remainder == 1) damage += 1;
        else if (remainder == 2) damage += 2;
        if (damage >= h) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll hi = h[i];
        ll low = 0;
        ll high = 2 * hi; // Safe upper bound
        ll min_attacks = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll full_cycles = mid / 3;
            ll remainder = mid % 3;
            ll damage = full_cycles * 5;
            if (remainder == 1) damage += 1;
            else if (remainder == 2) damage += 2;
            if (damage >= hi) {
                min_attacks = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        t += min_attacks;
    }
    cout << t << endl;
    return 0;
}