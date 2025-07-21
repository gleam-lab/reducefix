#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    while (true) {
        bool all_zero = true;
        rep(i, n) {
            if (h[i] > 0) {
                all_zero = false;
                if ((ans + 1) % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                ans++;
            }
        }
        if (all_zero) break;
    }

    cout << ans << endl;
}