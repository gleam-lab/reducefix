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
        // Determine damage: 3 if T is multiple of 3, else 1
        ll damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost alive enemy
        h[idx] -= damage;
        
        // If current enemy's health becomes 0 or less, move to next enemy
        if (h[idx] <= 0) {
            idx++;
        }
    }
    
    cout << T << endl;
    return 0;
}