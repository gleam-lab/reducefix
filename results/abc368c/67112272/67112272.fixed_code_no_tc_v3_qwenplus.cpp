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
        // Determine damage based on T
        ll damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost alive enemy
        if (h[idx] > 0) {
            h[idx] -= damage;
        }
        
        // Move to next enemy if current one is defeated
        while (idx < n && h[idx] <= 0) {
            idx++;
        }
    }
    
    cout << T << endl;
    return 0;
}