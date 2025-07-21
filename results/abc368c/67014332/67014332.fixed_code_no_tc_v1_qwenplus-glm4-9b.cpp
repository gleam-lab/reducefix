#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Iterate over each enemy
    for (ll i = 0; i < n; ++i) {
        ll health = h[i];
        ll attacks = health; // Each unit of health needs one attack

        // If the number of attacks is a multiple of 3, we can
        // perform 3 attacks in a row to remove all health in one go
        while (attacks % 3 == 0) {
            attacks /= 3;
            ans += 3; // Perform 3 attacks at once
        }

        // If after removing the multiples of 3, the remaining attacks are less than 3
        if (attacks < 3) {
            ans += attacks; // Directly add the remaining attacks
        } else { // If the remaining attacks are 3 or more
            ans += 3; // Perform 3 attacks at once
            attacks -= 3;
            // Now, handle the remaining attacks which are less than 3
            ans += attacks;
        }
    }

    cout << ans << endl;
}