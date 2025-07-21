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
        ll h = H[i];
        if (h == 0) continue;
        ll cycles = h / 5;
        T += cycles * 3;
        h -= cycles * 5;
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