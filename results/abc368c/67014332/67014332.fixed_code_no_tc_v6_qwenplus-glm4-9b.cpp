#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> health(n);
    for (ll &h : health) cin >> h;

    // We iterate over the health array
    for (ll i = 0; i < n; ++i) {
        // While the health of the current enemy is greater than 0
        while (health[i] > 0) {
            // If the current enemy's health is exactly divisible by 3, we attack 3 times
            if (health[i] % 3 == 0) {
                health[i] -= 3;
                ans += 3;
            }
            // If the current enemy's health is not divisible by 3, we attack once
            else {
                health[i]--;
                ans++;
            }
        }
    }

    cout << ans;
}