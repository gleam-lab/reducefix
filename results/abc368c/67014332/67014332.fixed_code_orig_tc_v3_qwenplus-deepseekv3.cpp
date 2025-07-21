#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll i = 0; i < n; ++i) {
        ll h = H[i];
        // Full cycles of 3 turns, each cycle reduces HP by 5
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;
        
        if (h > 0) {
            if (h <= 2) {
                T += h;
            } else {
                T += 3; // h = 3 or 4: need 3 turns (1+1+3)
            }
        }
    }
    cout << T << endl;
    return 0;
}