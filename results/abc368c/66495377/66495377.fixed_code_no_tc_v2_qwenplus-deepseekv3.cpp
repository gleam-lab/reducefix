#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_damage(ll t) {
    ll full_cycles = t / 3;
    ll remaining = t % 3;
    return full_cycles * 5 + remaining * (remaining == 1 ? 1 : (remaining == 2 ? 2 : 0));
}

ll find_min_attacks(ll h) {
    ll low = 0, high = 2 * h;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (calculate_damage(mid) >= h) {
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
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        ll required_attacks = find_min_attacks(h);
        t += required_attacks;
    }
    
    cout << t << endl;
    return 0;
}