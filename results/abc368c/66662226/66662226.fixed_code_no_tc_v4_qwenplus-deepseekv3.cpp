#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll t = 0;
    rep(i, n) {
        ll hi = h[i];
        if (hi <= 0) continue;
        
        // The number of full triple attacks (3 damage) and remaining attacks (1 damage)
        ll full_cycles = hi / 3;
        t += full_cycles * 3;
        hi -= full_cycles * 3;
        
        if (hi > 0) {
            if (t % 3 == 2) {
                t += 1;
                hi -= 1;
                if (hi > 0) {
                    t += 1;
                    hi -= 1;
                }
            } else if (t % 3 == 1) {
                t += 1;
                hi -= 1;
                if (hi > 0) {
                    t += 1;
                    hi -= 1;
                }
            } else {
                t += 1;
                hi -= 1;
                if (hi > 0) {
                    t += 1;
                    hi -= 1;
                }
            }
        }
    }
    cout << t << endl;
    return 0;
}