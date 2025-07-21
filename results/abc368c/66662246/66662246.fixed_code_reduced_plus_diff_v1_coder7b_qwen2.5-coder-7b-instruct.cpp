#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    for (ll& h : a) {
        if (h <= 0) continue;
        if (h % 3 == 0) {
            ans += h / 3;
            h = 0;
        } else {
            ans += h / 3 + 1;
            h %= 3;
        }
    }

    // Continue attacking until all enemies' health becomes 0 or less
    while (true) {
        bool done = true;
        rep(i, n) {
            if (a[i] > 0) {
                done = false;
                break;
            }
        }
        if (done) break;

        ans++;
        for (ll& h : a) {
            if (h > 0) {
                if (ans % 3 == 0) {
                    h -= 3;
                } else {
                    h--;
                }
            }
        }
    }

    cout << ans << endl;
}