#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_attacks(ll &T, ll h) {
    ll low = 0;
    ll high = 2 * h; // Upper bound
    ll best_T_total = high;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll full_cycles = mid / 3;
        ll remainder = mid % 3;
        ll damage = full_cycles * 5;
        if (remainder == 1) {
            damage += 1;
        } else if (remainder == 2) {
            damage += 2;
        }
        if (damage >= h) {
            best_T_total = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return best_T_total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        ll low = 0;
        ll high = 2 * h;
        ll best_T_total = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll full_cycles = mid / 3;
            ll remainder = mid % 3;
            ll damage = full_cycles * 5;
            if (remainder == 1) {
                damage += 1;
            } else if (remainder == 2) {
                damage += 2;
            }
            if (damage >= h) {
                best_T_total = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        T += best_T_total;
    }
    
    cout << T << endl;
    
    return 0;
}