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
    for (ll h : H) {
        if (h == 0) continue;
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}