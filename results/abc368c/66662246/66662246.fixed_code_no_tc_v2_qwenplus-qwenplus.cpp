#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to calculate minimum T for one enemy
ll calcT(int h) {
    // We want to maximize the number of triple attacks (every 3 turns, -3 health)
    // Each triple attack takes 3 seconds and does 3 damage => equivalent to 1 attack every 3 turns
    // Let x be the number of full triple attacks we can do
    ll x = h / 3;
    ll remaining = h % 3;
    
    if (remaining == 0) {
        return x * 3;
    } else {
        // If there's a remainder, we need extra attacks
        // Each normal attack reduces health by 1
        // The triple attacks must be scheduled at multiples of 3
        // So we need to find the earliest T such that:
        // - total damage is h
        // - triple attacks happen at T divisible by 3
        
        // We try different values of triple attacks (0, 1, 2, ...)
        // For each, compute required T using math

        // Try 0, 1, 2 triple attacks more than x
        ll minT = LLONG_MAX;
        for (ll k = 0; k <= 2; ++k++) {
            ll tripleAttacks = x + k;
            ll damageFromTriple = tripleAttacks * 3;
            if (damageFromTriple >= h) {
                // Need to find T such that we have exactly tripleAttacks triple attacks
                // And enough normal attacks to make total damage >= h
                
                ll low = 0, high = 2 * tripleAttacks + 10;
                while (low < high) {
                    ll mid = (low + high) / 2;
                    
                    // Number of triple attacks by time mid: floor(mid / 3)
                    ll actualTriple = mid / 3;
                    ll normalAttacks = mid - actualTriple;
                    
                    if (actualTriple >= tripleAttacks && actualTriple * 3 + normalAttacks >= h) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }
                
                minT = min(minT, low);
            }
        }
        
        return minT;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];

    ll ans = 0;
    rep(i, n) {
        ans += calcT(H[i]);
    }

    cout << ans << endl;
}