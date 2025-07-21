#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> health(n);
    for (ll i = 0; i < n; ++i) {
        cin >> health[i];
    }

    ll T = 0;
    for (ll i = 0; i < n; ++i) {
        // Calculate how many full attacks we need for this enemy
        ll full_attacks = health[i] / 3;
        // Add the full attacks to T
        T += full_attacks;
        // If there's a remainder, we need one more attack
        if (health[i] % 3 > 0) {
            T += 1;
        }
    }

    cout << T;
}