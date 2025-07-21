#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> row, col, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        row.insert(x);
        col.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // Initial count of positions not in any occupied row or column
    int ans = (n - row.size()) * (n - col.size());

    // Subtract cells attacked via diag1: i + j = d
    for (int d : diag1) {
        int lo = 1, hi = n;
        int min_i = max(1LL, d - n);
        int max_i = min(n, d - 1);

        if (min_i > max_i) continue;

        set<int> covered;

        for (int r : row) {
            int j = d - r;
            if (1 <= j && j <= n) covered.insert(r);
        }

        for (int c : col) {
            int i = d - c;
            if (1 <= i <= n) covered.insert(i);
        }

        ans -= (max_i - min_i + 1) - covered.size();
    }

    // Subtract cells attacked via diag2: i - j = d
    for (int d : diag2) {
        int lo = 1, hi = n;
        int min_i = max(1LL, d + 1);
        int max_i = min(n, n + d);

        if (min_i > max_i) continue;

        set<int> covered;

        for (int r : row) {
            int j = r - d;
            if (1 <= j && j <= n) covered.insert(r);
        }

        for (int c : col) {
            int i = c + d;
            if (1 <= i <= n) covered.insert(i);
        }

        ans -= (max_i - min_i + 1) - covered.size();
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}