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
        // Calculate the number of full cycles (3 attacks: 1,1,3 -> total 5 damage per 2 steps)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        ll remaining = h % 5;
        
        if (remaining > 0) {
            if (remaining <= 1) {
                T += 1;
            } else if (remaining <= 3) {
                T += 2;
            } else {
                T += 3;
            }
        }
    }
    cout << T << endl;
}