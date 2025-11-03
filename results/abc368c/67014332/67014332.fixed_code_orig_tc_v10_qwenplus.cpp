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
    ll tri = 1; // current turn modulo 3 (1-indexed: 1,2,3 -> 1,2,1)
    
    for (int i = 0; i < n; i++) {
        while (h[i] > 0) {
            if (tri == 3) {
                h[i] -= 3;
                tri = 1;
            } else {
                h[i] -= 1;
                tri++;
            }
            ans++;
        }
    }
    
    cout << ans;
    return 0;
}