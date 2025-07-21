#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll ans = 0;
    rep(i, n) {
        ll current = h[i];
        ll full_cycles = current / 5;
        ll remainder = current % 5;
        
        ans += full_cycles * 3;
        if (remainder > 0) {
            if (remainder <= 2) {
                ans += remainder;
            } else {
                ans += 3;
            }
        }
    }
    
    // Now, we need to adjust for overlapping attacks where earlier enemies might affect T
    // But the above approach misses the exact sequence, so we need a better way
    // Let's think differently: for each attack, it's either +1 or +3 damage based on T
    
    // Alternative approach: calculate the exact T where each enemy's health is exhausted
    // Each enemy i is attacked in turns T_i, T_i + 1, T_i + 2, etc., where T_i is the first attack on enemy i
    // T_i is sum of attacks on previous enemies
    
    // So, for each enemy i, the number of attacks needed is the minimal T where the sum of damages is >= H_i
    // The sum of damages after t attacks is: t + 2*(t / 3)
    // Because every 3rd attack adds an extra 2 damage (3 instead of 1)
    
    // So, for each enemy i, we need to find the minimal t_i such that t_i + 2*(t_i / 3) >= H_i
    // Then, the total T is sum of t_i for all enemies
    
    // Binary search for each t_i
    ans = 0;
    ll sum_prev_attacks = 0;
    rep(i, n) {
        ll hi = h[i];
        ll low = 0;
        ll high = 3 * hi; // A safe upper bound
        ll t_i = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = mid + 2 * (mid / 3);
            if (damage >= hi) {
                t_i = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        sum_prev_attacks += t_i;
        ans = sum_prev_attacks;
    }
    
    cout << ans << endl;
}