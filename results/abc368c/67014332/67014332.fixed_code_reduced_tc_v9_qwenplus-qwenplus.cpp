#include<bits/stdc++.h>
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
    ll tri = 1;  // Tracks current turn modulo 3

    for (int i = 0; i < n; ++i) {
        ll h = H[i];

        while (h > 0) {
            if (tri == 3) {
                h -= 3;
                tri = 1;
            } else {
                h -= 1;
                tri++;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}