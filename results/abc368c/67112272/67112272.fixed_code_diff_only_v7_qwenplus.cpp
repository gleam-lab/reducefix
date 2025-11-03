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
    int index = 0; // current enemy being attacked
    
    while (index < n) {
        T++;
        // Skip enemies that are already defeated
        while (index < n && h[index] <= 0) index++;
        if (index >= n) break;
        
        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            h[index] -= 3;
        } else {
            h[index] -= 1;
        }
    }
    
    cout << T << endl;
    return 0;
}