#include <iostream>
using namespace std;
using ll = long long;

ll num_attack(ll h) {
    ll cnt = 0;
    while (h > 0) {
        if (cnt % 3 == 0 || h == 1) {
            cnt++; // If cnt is a multiple of 3 or h is 1, attack once
        } else {
            cnt += 3; // Otherwise, attack three times
            h -= 3;   // Decrease h by 3
        }
        h--; // Always decrease h by 1 after each attack
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(h); // Update t with the number of attacks for current enemy
    }
    cout << t << endl; // Output the total number of attacks needed
    return 0;
}