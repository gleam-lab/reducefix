#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    vector<pair<int, int>> pieces(m);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total safe positions excluding rows and columns
    int ans = (n - rows.size()) * (n - cols.size());

    // Now remove overlaps from diagonal lines

    map<pair<int, int>, bool> covered;

    for (auto [x, y] : pieces) {
        int d1 = x + y;
        int d2 = x - y;

        // For diagonal d1 (i+j=d1)
        // Length of diagonal: min(d1-1, n) - max(1, d1-n) + 1
        int l = max(1LL, d1 - n);
        int r = min(n, d1 - 1);
        if (l <= r) {
            int cnt = r - l + 1;
            for (int i = l; i <= r; ++i) {
                int j = d1 - i;
                if (!rows.count(i) && !cols.count(j)) {
                    if (!covered.count({i, j})) {
                        ans--;
                        covered[{i, j}] = true;
                    }
                }
            }
        }

        // For anti-diagonal d2 (i-j=d2)
        // i ranges from max(1, d2+1) to min(n, n+d2)
        l = max(1LL, d2 + 1);
        r = min(n, n + d2);
        if (l <= r) {
            int cnt = r - l + 1;
            for (int i = l; i <= r; ++i) {
                int j = i - d2;
                if (!rows.count(i) && !cols.count(j)) {
                    if (!covered.count({i, j})) {
                        ans--;
                        covered[{i, j}] = true;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}