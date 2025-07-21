#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    while (true) {
        bool any_positive = false;
        rep(i, n) {
            if (h[i] > 0) {
                any_positive = true;
                if ((ans + 1) % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
            }
        }
        ans++;
        if (!any_positive) break;
    }

    cout << ans - 1 << endl;
}