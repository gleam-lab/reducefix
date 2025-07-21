#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; i++) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        if (h <= 0) continue;
        
        // Calculate full cycles of 3 attacks (5 damage per cycle)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;
        
        if (h > 0) {
            // Determine the attacks needed for the remaining health
            if (T % 3 == 0) {
                // Next attack is a 3-damage attack
                if (h <= 3) {
                    T += 1;
                    h = 0;
                } else {
                    T += 1;
                    h -= 3;
                    T += h;
                    h = 0;
                }
            } else if (T % 3 == 1) {
                // Next attack is 1 damage, then possibly another 1 or 3
                if (h <= 1) {
                    T += 1;
                    h = 0;
                } else {
                    T += 1;
                    h -= 1;
                    if (h <= 1) {
                        T += 1;
                        h = 0;
                    } else {
                        T += 1;
                        h -= 1;
                        if (h <= 3) {
                            T += 1;
                            h = 0;
                        } else {
                            T += 1;
                            h -= 3;
                            T += h;
                            h = 0;
                        }
                    }
                }
            } else if (T % 3 == 2) {
                // Next attack is 1 damage, then 3 damage
                if (h <= 1) {
                    T += 1;
                    h = 0;
                } else {
                    T += 1;
                    h -= 1;
                    if (h <= 3) {
                        T += 1;
                        h = 0;
                    } else {
                        T += 1;
                        h -= 3;
                        T += h;
                        h = 0;
                    }
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}