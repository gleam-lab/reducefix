#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll &x : h) cin >> x;
    
    ll ans = 0;
    
    // If the number of enemies is divisible by 3, we can take advantage of this.
    // We can attack every third enemy with a multiple of 3 damage, so we calculate
    // how many full attacks of 3 damage we can do in each step.
    for (ll i = 0; i < n; i += 3) {
        ll remaining = h[i];
        while (remaining > 0) {
            // If T is a multiple of 3, attack with 3 damage, otherwise 1 damage.
            // Since we're attacking every third enemy, we increment T for every
            // successful attack of either 1 or 3 damage.
            if (remaining >= 3) {
                remaining -= 3;
                ans += 3;
            } else {
                remaining -= 1;
                ans += 1;
            }
        }
    }

    // For any remaining enemies not processed in full sets of 3, process them one by one.
    // Since we're left with less than 3, we need to add the number of such attacks
    // to the answer.
    for (ll i = 1; i < n; i += 3) {
        ll remaining = h[i];
        while (remaining > 0) {
            remaining -= 1;
            ans += 1;
        }
    }
    
    cout << ans << endl;
}