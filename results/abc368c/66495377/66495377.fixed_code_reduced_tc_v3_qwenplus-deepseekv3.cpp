#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attacks(ll h) {
    ll groups = h / 5;
    ll remaining = h % 5;
    ll attacks = groups * 3;
    if (remaining > 0) {
        if (remaining <= 1) {
            attacks += 1;
        } else if (remaining <= 3) {
            attacks += 2;
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
        ll attacks_needed = num_attacks(h[i]);
        t += attacks_needed;
    }
    
    cout << t << endl;
    return 0;
}