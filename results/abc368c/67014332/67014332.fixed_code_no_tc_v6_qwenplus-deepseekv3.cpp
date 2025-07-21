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
        if (h == 0) continue;
        
        // Each group of 3 attacks deals 5 damage (1+1+3)
        ll groups = h / 5;
        T += groups * 3;
        h %= 5;
        
        if (h == 0) continue;
        
        // Now handle the remainder
        if (T % 3 == 0) {
            // Next attack is 1 damage (T+1)
            if (h <= 1) {
                T += 1;
            } else {
                // After 1, next is 1 (T+2)
                if (h <= 2) {
                    T += 2;
                } else {
                    // Then 3 (T+3)
                    T += 3;
                }
            }
        } else if (T % 3 == 1) {
            // Next attack is 1 damage (T+1)
            if (h <= 1) {
                T += 1;
            } else {
                // Then 3 (T+2)
                if (h <= 3) {
                    T += 2;
                } else {
                    // Then 1 (T+3)
                    T += 3;
                }
            }
        } else { // T % 3 == 2
            // Next attack is 3 damage (T+1)
            if (h <= 3) {
                T += 1;
            } else {
                // Then 1 (T+2)
                T += 2;
            }
        }
    }
    cout << T << endl;
    return 0;
}