#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll T = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] <= 0) continue;
        // The attacks for this enemy depend on T's current value
        // We can decompose the attacks into chunks of 3 steps (1,1,3)
        ll full_cycles = h[i] / 5;
        T += full_cycles * 3;
        h[i] -= full_cycles * 5;
        
        while (h[i] > 0) {
            T++;
            if (T % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i] -= 1;
            }
        }
    }
    cout << T << endl;
}