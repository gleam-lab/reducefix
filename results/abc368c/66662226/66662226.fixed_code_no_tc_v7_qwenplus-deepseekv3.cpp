#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll T = 0;
    for (ll h : H) {
        // Calculate full cycles (each cycle is 3 attacks dealing 5 damage)
        ll cycles = h / 5;
        T += cycles * 3;
        ll remaining = h % 5;
        
        if (remaining == 0) continue;
        
        // The remaining health is 1-4. We can attack until it's <=0.
        // The attacks could be part of the ongoing T sequence.
        // The next attack is at T+1, then T+2, etc.
        // The attack at T+1 is mod3=1 (1 damage), T+2 is mod3=2 (1), T+3 is mod3=0 (3).
        // So, find the minimal T' > current T where the attacks reduce remaining to <=0.
        // We can simulate the required steps.
        ll needed = 0;
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}