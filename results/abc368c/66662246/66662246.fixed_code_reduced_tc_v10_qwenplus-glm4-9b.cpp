#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll total_attacks = 0;
    for (ll health : h) {
        if (health % 3 == 0) {
            health = health / 3;
        } else {
            health = (health + 3) / 3; // If health is not divisible by 3, add 3 to make it divisible and then divide by 3
        }
        total_attacks += health;
    }

    cout << total_attacks << endl;
}