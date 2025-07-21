#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calculate_attacks(ll health) {
    ll attacks = 0;
    if (health % 3 == 0) {
        attacks = health / 3;
    } else if (health % 3 == 1) {
        attacks = (health / 3) + 2;
    } else { // health % 3 == 2
        attacks = (health / 3) + 1;
    }
    return attacks;
}

int main() {
    int n;
    cin >> n;
    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll health;
        cin >> health;
        total_attacks += calculate_attacks(health);
    }
    cout << total_attacks << endl;
}