#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0;
    cin >> n;
    vector<ll> healths(n);
    
    // Read health values
    for (ll &h : healths) {
        cin >> h;
    }
    
    // Process each enemy's health
    for (ll h : healths) {
        // Calculate full cycles of 3 hits
        ans += h / 3;
        // Remaining health after full cycles
        h %= 3;
        
        // If remaining health, add the minimum number of attacks needed
        if (h > 0) {
            ans += h;
        }
    }
    
    cout << ans << endl;
}