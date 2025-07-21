#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        ll full_cycles = h / 5;
        ll remaining = h % 5;
        ll attacks;
        if (remaining == 0) {
            attacks = full_cycles * 3;
        } else if (remaining <= 2) {
            attacks = full_cycles * 3 + remaining;
        } else {
            attacks = full_cycles * 3 + 3;
        }
        ans += attacks;
    }
    cout << ans << endl;
}