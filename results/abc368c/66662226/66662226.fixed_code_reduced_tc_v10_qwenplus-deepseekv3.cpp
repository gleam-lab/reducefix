#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];
    
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        // Calculate full cycles of 3 attacks (5 damage per cycle)
        ll cycles = h / 5;
        ll remaining = h % 5;
        
        // Each full cycle contributes 3 to T
        ans += cycles * 3;
        
        // Handle remaining health
        if (remaining > 0) {
            if (remaining <= 1) {
                ans += 1;
            } else if (remaining <= 3) {
                ans += 2;
            } else {
                ans += 3;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}