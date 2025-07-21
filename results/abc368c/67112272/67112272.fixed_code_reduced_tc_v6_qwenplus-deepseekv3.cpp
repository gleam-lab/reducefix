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
        ll cycles = h[i] / 5;
        ll remainder = h[i] % 5;
        
        ans += cycles * 3;
        if (remainder > 0) {
            if (remainder <= 2) {
                ans += remainder;
            } else {
                ans += 3;
            }
        }
    }
    cout << ans << endl;
}