#include <iostream>
using namespace std;
using ll = long long;

ll calculate_attacks(ll health) {
    if (health <= 3) {
        return health;
    }
    // Calculate number of attacks needed for full health blocks of 3
    ll full_blocks = health / 3;
    // Calculate remaining health after full blocks
    ll remaining = health % 3;
    // If remaining is 0, no extra attacks are needed
    if (remaining == 0) {
        return full_blocks * 3;
    }
    // Otherwise, 3 attacks are needed
    return full_blocks * 3 + 3;
}

int main() {
    ll n;
    cin >> n;
    ll t = 0;
    for (ll i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += calculate_attacks(h);
    }
    cout << t << endl;
    return 0;
}