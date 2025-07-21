#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll ans = 0;
    rep(i, n) {
        ll hi = h[i];
        ll full_cycles = hi / 5;
        ll remaining = hi % 5;
        
        ll temp = full_cycles * 3;
        if (remaining > 0) {
            if (remaining <= 2) {
                temp += remaining;
            } else {
                temp += 3;
            }
        }
        
        ans += temp;
    }
    
    // Now, we need to adjust for overlapping attacks when previous enemies are still being attacked.
    // The initial approach may not account for the exact sequence when enemies are not attacked in isolation.
    // Therefore, a more precise method is required.
    
    // Alternative approach: For each enemy, calculate the exact number of attacks considering the attack pattern.
    ans = 0;
    vector<ll> attacks(n, 0);
    rep(i, n) {
        ll hi = h[i];
        // Each attack on this enemy is either 1 or 3 damage, based on T.
        // The total attacks can be computed by solving:
        // The number of 1-damage attacks (a) and 3-damage attacks (b) such that a + 3*b >= hi, and a + b is minimized.
        // But since the attacks alternate, we need to find the minimal T where the sum of damages up to T is >= hi.
        // The damage sequence is 1, 1, 3, 1, 1, 3, etc.
        // So, per 3 attacks, total damage is 5.
        ll full_cycles = hi / 5;
        ll rem = hi % 5;
        ll a = full_cycles * 3;
        if (rem > 0) {
            if (rem <= 2) {
                a += rem;
            } else {
                a += 3;
            }
        }
        attacks[i] = a;
    }
    
    // However, the attacks are sequential, so the actual T for each enemy is the cumulative sum up to its position.
    ans = 0;
    ll current_T = 0;
    rep(i, n) {
        ll hi = h[i];
        // The first attack on this enemy is at T = current_T + 1.
        ll low = 1, high = 3 * hi, best_T = 3 * hi;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll full_cycles = mid / 3;
            ll rem = mid % 3;
            ll damage = full_cycles * 5;
            if (rem == 1) damage += 1;
            else if (rem == 2) damage += 2;
            if (damage >= hi) {
                best_T = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // The actual T for this enemy is current_T + best_T.
        ans = current_T + best_T;
        current_T = ans;
    }
    
    cout << ans << endl;
    return 0;
}