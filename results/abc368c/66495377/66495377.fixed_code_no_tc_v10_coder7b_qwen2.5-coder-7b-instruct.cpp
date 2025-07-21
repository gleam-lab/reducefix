#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to calculate the number of attacks needed for a single enemy
ll num_attack(ll h) {
    ll cnt = 0;
    // Calculate how many full sets of 3 hits can be made
    cnt += h / 3;
    // Remaining health after full sets
    h %= 3;
    // Additional hits needed for remaining health
    cnt += h;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        // Add the number of attacks needed for this enemy to the total
        total_attacks += num_attack(h);
    }
    // Print the total number of attacks required
    cout << total_attacks << endl;
}