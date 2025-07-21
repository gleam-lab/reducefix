#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    ll t = 0;  // This variable now represents the cumulative number of hits, not attacks.

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        // Calculate the number of hits needed for this enemy.
        // Each hit deals either 1 or 3 damage. We can calculate the number of hits
        // needed to defeat the enemy by rounding up the health divided by 3 and
        // adding the remainder divisibility by 3.
        ll hits_needed = (h[i] + 2) / 3;  // Round up division by 3
        t += hits_needed;  // Add the number of hits needed for this enemy to the total
    }

    cout << t << endl;
}