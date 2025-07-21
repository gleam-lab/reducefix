#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attacks(ll h) {
    ll full_cycles = h / 5;
    ll remaining = h % 5;
    ll attacks = 3 * full_cycles;
    if (remaining > 0) {
        if (remaining <= 2) {
            attacks += remaining;
        } else {
            attacks += 3;
        }
    }
    return attacks;
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
        ll attacks = num_attacks(h[i]);
        t += attacks;
    }
    
    cout << t << endl;
}