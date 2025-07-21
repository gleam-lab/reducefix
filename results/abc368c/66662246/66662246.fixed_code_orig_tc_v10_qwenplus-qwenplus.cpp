#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // Precompute the number of full 3-attack cycles (each does 5 damage)
    // Then handle remaining health
    rep(i, n) {
        ll h = H[i];
        if (h == 0) continue;

        // Each 3 attacks deal 5 damage
        ll cycles = h / 5;
        ll remainder = h % 5;

        T += cycles * 3;

        if (remainder > 0) {
            T += (remainder + 1) / 2; // Every two attacks do 1+3 damage max
        }
    }

    cout << T << "\n";
    return 0;
}