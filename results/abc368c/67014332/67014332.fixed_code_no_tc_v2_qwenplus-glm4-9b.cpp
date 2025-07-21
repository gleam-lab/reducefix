#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    ll ans = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
        // Calculate how many full cycles of 3 attacks we can perform on this enemy
        ans += h[i] / 3;
        // Calculate the remaining health after the full cycles
        h[i] %= 3;
        // For the remaining health, we need only one attack per remaining health point
        ans += h[i];
    }

    cout << ans;
}