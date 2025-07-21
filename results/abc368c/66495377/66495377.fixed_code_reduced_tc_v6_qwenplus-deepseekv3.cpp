#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll compute_attacks(ll h) {
    ll low = 0, high = 2 * h; // Upper bound can be 2*h since each attack deals at least 1 damage
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 4 + (mid % 3);
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
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = compute_attacks(h[i]);
        ll low = t, high = t + 2 * h[i];
        ll best_t = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = (mid / 3) * 4 + (mid % 3) - (t / 3) * 4 - (t % 3);
            if (damage >= h[i]) {
                best_t = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        t = best_t;
    }
    
    cout << t << endl;
    return 0;
}