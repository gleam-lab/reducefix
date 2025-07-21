#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the minimum number of attacks needed for a single enemy
ll required_attacks(ll h) {
    // Each 3 attacks: 3 damage on 3rd attack, 1 otherwise => total 5 damage every 3 attacks
    ll full_cycles = h / 5;
    ll remaining_damage = h % 5;

    ll attacks = full_cycles * 3;
    if (remaining_damage > 0) {
        attacks += 1;  // one more attack if some damage remains
        if (remaining_damage >= 3)
            attacks += 1;  // second attack needed if still not dead
    }
    return attacks;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll attacks_needed = required_attacks(H[i]);
        T += attacks_needed;
    }

    cout << T << endl;
}