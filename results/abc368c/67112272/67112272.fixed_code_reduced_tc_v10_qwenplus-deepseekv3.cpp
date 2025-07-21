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
        ll full_cycles = h[i] / 5;
        ll remainder = h[i] % 5;
        
        ans += full_cycles * 3;
        if (remainder > 0) {
            if (remainder <= 2) {
                ans += remainder;
            } else {
                ans += 3;
            }
        }
    }
    
    // The above approach might not account for the exact sequence of attacks,
    // so we need to verify if the total damage is sufficient.
    // However, the initial approach fails for certain cases, like the provided test case.
    // We need to find a better way.
    // Let's think differently: for each enemy, the number of attacks is the ceiling of H_i / 1 or 3, but considering the attack pattern.
    // Alternatively, we can compute the minimal T where the cumulative damage from T attacks is >= H_i for each enemy.
    // The cumulative damage after T attacks is floor((T / 3)) * 5 + (T % 3) * 1 if T % 3 != 0, else (T / 3) * 5.
    // So, for each H_i, we need to find the smallest T_i such that floor((T_i / 3)) * 5 + (T_i % 3) * 1 >= H_i.
    // Then, the answer is the maximum of T_i over all enemies, because we need to wait until the last enemy is defeated.
    
    // So, we need to compute T_i for each H_i.
    // The relationship between T_i and H_i can be derived as follows:
    // Let k = T_i / 3, r = T_i % 3.
    // Then, damage = 5k + r (if r < 3).
    // We need 5k + r >= H_i, with r in 0..2.
    // The minimal T_i is 3k + r, where 5k + r >= H_i and r is minimal possible.
    
    // To find k and r:
    // For a given H_i, k = floor((H_i - 1) / 5) (since 5k + 0.999... <= H_i -1)
    // Then, 5k <= H_i -1, so H_i - 5k is the remaining damage needed.
    // The remaining damage can be covered by r = ceil((H_i -5k)/1), but since r can be at most 2 (because 5k + 3 would be part of the next cycle, which is 5(k+1)).
    // So, wait, better approach:
    // For a given H_i, find the smallest T such that the total damage >= H_i.
    // The total damage after T attacks is:
    // D = 5*(T // 3) + (T % 3)
    // We need D >= H_i.
    // So, T can be found by solving this inequality.
    
    // Let's compute T_i for each H_i.
    ans = 0;
    for (ll hi : h) {
        ll low = 0, high = 2 * hi; // Upper bound can be large enough.
        ll T_i = high;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = (mid / 3) * 5 + (mid % 3);
            if (damage >= hi) {
                T_i = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans = max(ans, T_i);
    }
    
    cout << ans << endl;
    return 0;
}