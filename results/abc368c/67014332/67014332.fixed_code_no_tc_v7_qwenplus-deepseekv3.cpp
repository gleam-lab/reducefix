#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll &h : H) cin >> h;
    
    ll ans = 0;
    for (ll h : H) {
        ll cycles = h / 5;
        ans += cycles * 3;
        ll rem = h % 5;
        
        if (rem > 0) {
            if (ans % 3 == 2) {
                // Next turn is a strong attack (T+1 is a multiple of 3)
                if (rem <= 3) {
                    ans += 1;
                } else {
                    ans += 2;
                }
            } else if (ans % 3 == 1) {
                // Next turn is a weak attack (T+1 is not a multiple of 3)
                if (rem <= 1) {
                    ans += 1;
                } else {
                    ans += 2;
                }
            } else { // ans % 3 == 0
                // Current turn is a strong attack if T is exact multiple of 3
                if (rem <= 3) {
                    ans += 1;
                } else {
                    ans += 2;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}