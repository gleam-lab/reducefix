#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        ll cycles = h / 5;
        ll rem = h % 5;
        ans += cycles * 3;
        if (rem > 0) {
            if (rem <= 3) {
                ans += (rem == 3) ? 1 : rem;
            } else {
                ans += 2; // rem is 4, which is 1 + 3 (two attacks)
            }
        }
    }
    cout << ans << endl;
    return 0;
}