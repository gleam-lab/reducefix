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

    ll T = 0;
    ll tri = 1; // Tracks current step modulo 3

    for (ll h : H) {
        // We simulate the attack process carefully to ensure correct timing
        while (h > 0) {
            if (tri == 3) {
                h -= 3;
                tri = 1;
                T++;
            } else {
                h -= 1;
                tri++;
                T++;
            }
        }
        tri = 1; // Reset for next enemy
    }

    cout << T << endl;
}