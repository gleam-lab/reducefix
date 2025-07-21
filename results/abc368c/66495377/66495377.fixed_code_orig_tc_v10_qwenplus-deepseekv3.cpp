#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_attacks(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = (mid / 3) * 3 + (mid - mid / 3) * 1;
        if (damage >= h) {
            high = mid;
        } else {
            low = mid + 1;
        }
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

    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll required = calculate_attacks(h[i]);
        total_attacks += required;
    }

    cout << total_attacks << endl;
    return 0;
}