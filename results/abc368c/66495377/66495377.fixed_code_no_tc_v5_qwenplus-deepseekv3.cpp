#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(ll T, const vector<ll>& H) {
    ll total_attacks = 0;
    for (ll h : H) {
        ll required = (h + 2) / 3; // Upper bound for attacks if all were 3 damage
        if (required > T) {
            return false;
        }
    }
    
    ll attacks_3 = T / 3;
    ll attacks_1 = T - attacks_3;
    
    for (ll h : H) {
        ll needed_3 = min(attacks_3, (h + 2) / 3);
        ll remaining = h - 3 * needed_3;
        if (remaining > 0) {
            if (remaining > attacks_1 - needed_3) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll left = 0;
    ll right = 3 * 1e18; // Upper bound to cover worst case
    
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (isPossible(mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    return 0;
}