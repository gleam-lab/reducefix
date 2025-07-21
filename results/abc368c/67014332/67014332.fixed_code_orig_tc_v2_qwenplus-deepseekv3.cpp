#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll ans = 0;
    ll tri = 1;
    
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        ll full_cycles = h / 5;
        ans += full_cycles * 3;
        h %= 5;
        
        while (h > 0) {
            ans++;
            if (tri % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
            tri++;
        }
    }
    
    cout << ans << endl;
    return 0;
}