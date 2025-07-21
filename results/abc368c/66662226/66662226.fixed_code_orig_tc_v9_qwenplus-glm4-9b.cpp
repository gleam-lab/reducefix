#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> remainder_counts(3, 0);
    // First pass, calculate the remainders and the strict attacks needed
    rep(i, n) {
        int health = h[i];
        while (health > 0) {
            remainder_counts[health % 3]++;
            health -= (health % 3);
        }
    }

    // Calculate the total number of attacks up to this point
    ll total_attacks = 0;
    ll current_attacks = 0;
    rep(i, 3) {
        total_attacks += current_attacks * (remainder_counts[i] + 1) + (remainder_counts[i] * (remainder_counts[i] + 1) / 2);
        current_attacks += remainder_counts[i];
    }

    // Print the total number of attacks
    cout << total_attacks << endl;

    return 0;
}