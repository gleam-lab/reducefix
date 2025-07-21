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
    for (ll hi : h) {
        ll full_cycles = hi / 5;
        ll remainder = hi % 5;
        
        ans += full_cycles * 3;
        if (remainder > 0) {
            if (remainder <= 3) {
                ans += 1;
            } else {
                ans += 2;
            }
        }
    }
    
    ll max_T = 0;
    ll current_T = 0;
    for (ll hi : h) {
        ll low = 0, high = 2 * hi;
        ll best_T = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll damage = (mid / 3) * 5 + (mid % 3 == 1 ? 3 : (mid % 3 == 2 ? 4 : 0));
            if (damage >= hi) {
                best_T = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        current_T += best_T;
        max_T = max(max_T, current_T);
    }
    cout << max_T << endl;
}