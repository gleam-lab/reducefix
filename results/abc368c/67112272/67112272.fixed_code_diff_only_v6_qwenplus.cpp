#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    
    ll T = 0;
    int idx = 0; // current enemy index
    
    while (idx < n) {
        T++;
        // Check if current frontmost alive enemy is at idx
        if (h[idx] <= 0) {
            idx++;
            continue;
        }
        
        // Attack the frontmost enemy (at idx)
        if (T % 3 == 0) {
            h[idx] -= 3;
        } else {
            h[idx] -= 1;
        }
        
        // If this enemy is defeated, move to next
        if (h[idx] <= 0) {
            idx++;
        }
    }
    
    cout << T << endl;
    return 0;
}