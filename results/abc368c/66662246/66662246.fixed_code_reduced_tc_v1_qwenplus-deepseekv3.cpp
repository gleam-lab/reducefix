#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll T = 0;
    rep(i, n) {
        ll remaining = H[i];
        // Calculate full cycles of 3 attacks (5 damage)
        ll full_cycles = remaining / 5;
        T += full_cycles * 3;
        remaining -= full_cycles * 5;
        // Handle remaining health
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    cout << T << endl;
}