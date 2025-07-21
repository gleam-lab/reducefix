#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll ans = 0;
    rep(i, n)
    {
        ll h = a[i];
        // Each attack sequence is: -1, -1, -3 (total of 5 damage in 3 seconds)
        // Find how many full cycles of 3 attacks we can do
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h -= full_cycles * 5;
        
        if (h > 0) {
            // Remaining damage needed after full cycles
            // We need to determine how many attacks are needed
            // If T+1, T+2, T+3 -> attacks at T+1 and T+2 are -1, T+3 is -3 if divisible by 3
            // So we simulate the last partial set
            
            // Try simulating just the remaining part
            ll extra = 0;
            while (h > 0) {
                ans++;
                extra++;
                if (extra % 3 == 0) {
                    h -= 3;
                } else {
                    h -= 1;
                }
            }
        }
    }
    cout << ans << endl;
}