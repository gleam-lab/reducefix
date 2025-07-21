#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll compute_attacks(ll t_start, ll h) {
    ll low = 0;
    ll high = 2 * h;  // Upper bound
    while (low < high) {
        ll mid = (low + high) / 2;
        ll damage = mid + 2 * (mid / 3);
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
    
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll required = compute_attacks(t, h[i]);
        t += required;
    }
    
    cout << t << endl;
    return 0;
}