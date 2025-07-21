#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 5;
        if (mid % 3 == 1) damage += 1;
        else if (mid % 3 == 2) damage += 2;
        if (damage >= h) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll required = calculate_attacks(h[i]);
        if (i > 0) {
            ll prev_required = calculate_attacks(h[i-1]);
            if (required < prev_required) {
                required = prev_required + (required - (prev_required % 3));
            }
        }
        t = max(t + 1, required);
    }
    cout << t << endl;
    return 0;
}