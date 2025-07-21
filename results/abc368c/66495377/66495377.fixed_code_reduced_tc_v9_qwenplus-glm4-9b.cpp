#include <iostream>
using namespace std;
using ll = long long;

ll calculate_attacks(ll health) {
    ll attacks = 0;
    while (health > 0) {
        if (health % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }
        attacks++;
    }
    return attacks;
}

int main() {
    ll t = 0;
    ll n;
    cin >> n;
    while (n--) {
        ll health;
        cin >> health;
        t += calculate_attacks(health);
    }
    cout << t << endl;
    return 0;
}