#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Total safe squares without considering diagonal overlaps
    int ans = (n - (int)rows.size()) * (n - (int)cols.size());

    // Subtract unsafe squares on diagonals that are not already excluded by row/col removal
    auto process_diag1 = [&](int d) {
        set<int> blocked;
        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= n)
                blocked.insert(r);
        }
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= n)
                blocked.insert(r);
        }

        int len;
        if (d <= n + 1)
            len = d - 1;
        else
            len = 2 * n - d + 1;
        ans -= (len - blocked.size());
    };

    auto process_diag2 = [&](int d) {
        set<int> blocked;
        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= n)
                blocked.insert(r);
        }
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= n)
                blocked.insert(r);
        }

        int len;
        if (d <= 0)
            len = n + d;
        else
            len = n - d + 1;
        ans -= (len - blocked.size());
    };

    for (int d : diag1) process_diag1(d);
    for (int d : diag2) process_diag2(d);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}