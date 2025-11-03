#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll tri = 1;
    
    for(int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        
        // Process in chunks of 5: each chunk takes 3 attacks (1 triple and 2 singles)
        // But we need to simulate the cycle properly
        while(h > 0) {
            if(tri == 3) {
                h -= 3;
                tri = 1;
            } else {
                h -= 1;
                tri++;
            }
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}