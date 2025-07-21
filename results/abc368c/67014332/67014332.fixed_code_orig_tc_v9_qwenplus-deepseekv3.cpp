#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    ll ans = 0;
    ll tri = 1; // tracks the position in the 3-attack cycle
    
    for (int i = 0; i < n; i++) {
        ll cycles = h[i] / 5;
        ans += cycles * 3;
        ll rem = h[i] % 5;
        
        while (rem > 0) {
            ans++;
            if (tri % 3 == 0) {
                rem -= 3;
            } else {
                rem -= 1;
            }
            tri++;
        }
    }
    
    cout << ans << endl;
    return 0;
}