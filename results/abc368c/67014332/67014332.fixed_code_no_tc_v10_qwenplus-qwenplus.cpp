#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }

    ll T = 0;
    ll tri = 0; // Count how many attacks have been made since the last triple attack

    for (ll i = 0; i < N; ++i) {
        ll h = H[i];

        while (h > 0) {
            T++;
            tri++;
            if (tri == 3) {
                tri = 0;
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}