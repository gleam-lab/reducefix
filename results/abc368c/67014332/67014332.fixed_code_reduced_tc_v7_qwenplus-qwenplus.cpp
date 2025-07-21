#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) cin >> H[i];

    ll T = 0, tri = 0; // tri counts how many attacks have been made since last triple attack

    for (ll h : H) {
        // For each enemy, determine how many total attacks needed
        while (h > 0) {
            T++;
            tri++;
            if (tri == 3) {
                h -= 3;
                tri = 0;
            } else {
                h -= 1;
            }
        }
        tri = 0; // reset for next enemy
    }

    cout << T << endl;
}