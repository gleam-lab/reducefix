#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n) {
        cin >> h[i];
    }
    
    ll T = 0;
    int current_enemy = 0;
    
    while (current_enemy < n) {
        T++;
        
        // Check if T is multiple of 3
        ll damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost enemy with health > 0
        h[current_enemy] -= damage;
        
        // If current enemy's health becomes 0 or less, move to next enemy
        if (h[current_enemy] <= 0) {
            current_enemy++;
        }
    }
    
    cout << T << endl;
    return 0;
}