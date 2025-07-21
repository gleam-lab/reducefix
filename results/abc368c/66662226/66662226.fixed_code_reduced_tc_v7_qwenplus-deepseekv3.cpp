#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    ll ans = 0;
    rep(i, n) {
        ll h = H[i];
        ll cycles = h / 5;
        ll rem = h % 5;
        ans += cycles * 5;
        h = rem;
        if (h > 0) {
            if (h <= 3) {
                if (h == 3) {
                    ans += 1;
                } else {
                    ans += h;
                }
            } else {
                ans += 3;
            }
        }
    }
    cout << ans << endl;
}