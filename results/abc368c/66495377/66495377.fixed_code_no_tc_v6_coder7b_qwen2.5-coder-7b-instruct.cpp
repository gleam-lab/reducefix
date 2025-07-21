#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the number of attacks needed for a single enemy
ll num_attack(ll t, ll h) {
    ll cnt = 0;
    // Calculate the number of full sets of 3 attacks that can be done
    cnt += h / 4; // 4 is used because we need to subtract 1 for each attack, and 3 for every third attack
    // Remaining health after full sets of 3 attacks
    int remind = h % 4;
    while (remind > 0) {
        t++;
        // Check if it's time for a special attack
        if (t % 3 == 0) {
            remind -= 3;
        } else {
            remind--;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll total_t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        // Add the number of attacks for this enemy to the total
        total_t += num_attack(total_t, h);
    }

    cout << total_t << endl;
}