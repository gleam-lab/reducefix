#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll T = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] <= 0) continue;
        // The attacks for this enemy depend on T up to now.
        // Need to find how many 3-damage attacks (T+1 divisible by 3) and 1-damage attacks.
        // Let’s model the attack sequence for this enemy.
        
        // The enemy is attacked from time T+1 onwards.
        // The attack pattern is: T+1 (1 damage), T+2 (1 damage), T+3 (3 damage), etc.
        // We need to find the minimal T' such that sum attacks >= h[i], where T' is the time when this enemy is defeated.
        
        ll low = 0, high = 2 * h[i]; // Upper bound can be adjusted
        ll best_T = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cnt3 = mid / 3;
            ll cnt1 = mid - cnt3;
            ll total = cnt1 * 1 + cnt3 * 3;
            if (total >= h[i]) {
                best_T = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Now, the actual T is increased by best_T, and during these attacks, the enemy is defeated.
        T += best_T;
    }
    
    cout << T << endl;
    return 0;
}