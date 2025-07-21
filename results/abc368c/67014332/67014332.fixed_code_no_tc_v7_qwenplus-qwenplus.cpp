#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    ll time = 0;
    ll tri = 1;

    for (ll h : H) {
        // While the enemy still has health
        while (h > 0) {
            // If it's a triple attack turn
            if (tri == 3) {
                h -= 3;
                tri = 1;
                time++;
            } else {
                // Regular attack
                h -= 1;
                tri++;
                time++;
            }
        }
        // After finishing this enemy, reset tri for next enemy
        tri = 1;
    }

    cout << time << endl;
}