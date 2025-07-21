#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll h : H) {
        // The attacks follow a pattern: 1, 1, 3, 1, 1, 3, ...
        // So every 3 attacks, the total damage is 1+1+3 = 5.
        // First, compute how many full cycles of 3 attacks (5 damage) are needed.
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        ll remaining_h = h % 5;
        
        // Now, handle the remaining health after full cycles.
        if (remaining_h > 0) {
            T += 1;
            remaining_h -= 1;
            if (remaining_h > 0) {
                T += 1;
                remaining_h -= 1;
                if (remaining_h > 0) {
                    // The third attack in the cycle deals 3 damage.
                    T += 1;
                    remaining_h -= 3;
                }
            }
        }
    }
    
    cout << T << endl;
    return 0;
}