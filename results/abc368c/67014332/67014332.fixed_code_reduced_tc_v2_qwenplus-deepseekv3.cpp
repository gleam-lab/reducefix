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
    ll current_attack = 1;
    
    for (ll i = 0; i < n; i++) {
        ll h = H[i];
        if (h == 0) continue;
        
        // Calculate full cycles (each cycle is 3 attacks dealing 5 damage)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;
        
        if (h > 0) {
            // Determine the remaining attacks needed
            if (current_attack % 3 == 1) {
                if (h <= 1) {
                    T += 1;
                    current_attack += 1;
                } else {
                    T += 1;
                    h -= 1;
                    current_attack += 1;
                    if (h > 0) {
                        if (current_attack % 3 == 0) {
                            T += 1;
                            h -= 3;
                            current_attack += 1;
                        } else {
                            T += 1;
                            h -= 1;
                            current_attack += 1;
                        }
                    }
                }
            } else if (current_attack % 3 == 2) {
                if (h <= 1) {
                    T += 1;
                    current_attack += 1;
                } else {
                    T += 1;
                    h -= 1;
                    current_attack += 1;
                    if (h > 0) {
                        if (current_attack % 3 == 0) {
                            T += 1;
                            h -= 3;
                            current_attack += 1;
                        } else {
                            T += 1;
                            h -= 1;
                            current_attack += 1;
                        }
                    }
                }
            } else { // current_attack % 3 == 0
                T += 1;
                h -= 3;
                current_attack += 1;
                if (h > 0) {
                    if (current_attack % 3 == 0) {
                        T += 1;
                        h -= 3;
                        current_attack += 1;
                    } else {
                        T += 1;
                        h -= 1;
                        current_attack += 1;
                    }
                }
            }
        }
    }
    
    cout << T << endl;
    return 0;
}