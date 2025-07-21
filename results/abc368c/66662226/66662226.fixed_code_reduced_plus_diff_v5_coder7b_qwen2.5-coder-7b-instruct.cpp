#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    rep(i, n) cin >> h[i];

    long long ans = 0;
    long long t = 0;

    while (true) {
        bool changed = false;
        rep(i, n) {
            if (h[i] > 0) {
                ++t;
                if (t % 3 == 0) h[i] -= 3;
                else --h[i];
                changed = true;
            }
        }
        if (!changed) break;
        ans = t;
    }

    cout << ans << '\n';
}