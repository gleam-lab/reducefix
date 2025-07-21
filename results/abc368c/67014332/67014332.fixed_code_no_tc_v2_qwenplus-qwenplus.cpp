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
    ll tri = 1;

    for (ll i = 0; i < N; ++i) {
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