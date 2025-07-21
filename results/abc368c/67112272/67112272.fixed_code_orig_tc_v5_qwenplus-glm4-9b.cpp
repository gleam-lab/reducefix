#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    ll ans = 0;
    
    // Read the healths of each enemy
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    // Process each enemy
    for (ll i = 0; i < n; ++i) {
        // While the current enemy still has health
        while (h[i] > 0) {
            // Calculate the number of 3-point attacks we can use
            ans += h[i] / 3;
            // Update the remaining health
            h[i] %= 3;
            // If the remaining health is not zero, we need to deal with it
            if (h[i] > 0) {
                ans += 1;
                h[i] = 0;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}