#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll t = 0;
    while (n > 0) {
        ll mod3 = t % 3; // Determine the current mode of the attack
        ll multiple_of_3 = t / 3;
        if (multiple_of_3 * 3 + mod3 > n) {
            // If the total damage in the current turn is more than the remaining enemies,
            // we can deal just enough damage to kill all enemies in this turn.
            ll needed_damage = n;
            t += (needed_damage - multiple_of_3 * 3) % 3;
            n = 0;
        } else {
            // Otherwise, deal the maximum possible damage and continue.
            t += 3;
            n -= 3;
        }
    }

    cout << t << endl;
    return 0;
}