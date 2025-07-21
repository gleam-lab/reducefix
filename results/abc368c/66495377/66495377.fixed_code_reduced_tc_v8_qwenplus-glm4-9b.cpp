#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll attack_count(ll health) {
    // When health is a multiple of 3, it takes exactly health/3 attacks.
    // If there's a remainder, it will take one additional attack.
    return (health + 2) / 3;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> enemy_health(n);
    ll total_attacks = 0;

    for (ll i = 0; i < n; ++i) {
        cin >> enemy_health[i];
    }

    for (ll health : enemy_health) {
        total_attacks += attack_count(health);
    }

    cout << total_attacks << endl;
    return 0;
}