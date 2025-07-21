#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < n; ++i)
using ll = long long;

int main() {
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    for (ll health : h) {
        // When health is divisible by 3, we can attack three times in a row to reduce it by 3 each time
        ans += health / 3;
        // Calculate the remainder
        ll remainder = health % 3;
        // If remainder is 1 or 2, we need to attack once more after the multiples of 3
        if (remainder > 0) {
            ans += 1;
            health -= remainder;
            // If after subtracting the remainder, the health can still be reduced by 1 more, add it to the answer
            if (health > 0) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}