#include <bits/stdc++.h>
using namespace std;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(begin(a) + 1, end(a));

    auto check = [&](i64 d) -> bool {
        int count = 0;
        for (int i = n; i > 0 && a[i] + d > a[n - m + 1]; --i) {
            if (a[i] + d <= a[n - m + 1]) break;
            ++count;
        }
        return count >= m;
    };

    vector<i64> ans(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        i64 l = 0, r = k;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            if (check(mid)) {
                ans[i] = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}