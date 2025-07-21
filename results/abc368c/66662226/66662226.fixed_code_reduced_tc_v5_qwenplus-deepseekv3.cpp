#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        // Calculate the number of full 3-turn cycles (5 damage per cycle)
        ll cycles = h / 5;
        ll rem = h % 5;
        
        // Each cycle contributes 3 turns and 5 damage
        ans += cycles * 3;
        h -= cycles * 5;
        
        // Handle the remaining damage
        while (h > 0) {
            ans++;
            if (ans % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}