#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total empty cells not attacked by row or column
    int ans = (n - rows.size()) * (n - cols.size());

    // Subtract cells attacked via diagonals that were counted in the above total

    for (auto d : diag1) {
        // For diagonal i+j=d
        set<int> covered_rows;

        // Intersections with rows used in 'rows'
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= n)
                covered_rows.insert(r);
        }

        // Intersections with columns used in 'cols'
        for (auto c : cols) {
            int r = d - c;
            if (1 <= r && r <= n)
                covered_rows.insert(r);
        }

        // Length of this diagonal
        int len;
        if (d <= n + 1) {
            len = d - 1;
        } else {
            len = 2 * n - d + 1;
        }

        // Remove points on this diagonal that were included in the initial count
        ans -= (len - covered_rows.size());
    }

    for (auto d : diag2) {
        // For diagonal i-j=d => i = j + d
        set<int> covered_rows;

        // Intersections with rows used in 'rows'
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= n)
                covered_rows.insert(r);
        }

        // Intersections with columns used in 'cols'
        for (auto c : cols) {
            int r = d + c;
            if (1 <= r && r <= n)
                covered_rows.insert(r);
        }

        // Intersections with diagonals from diag1
        // Solve:
        // i + j = e
        // i - j = d
        // => i = (e + d)/2, j = (e - d)/2
        for (auto e : diag1) {
            if ((e + d) % 2 == 0 && (e - d) % 2 == 0) {
                int i = (e + d) / 2;
                int j = (e - d) / 2;
                if (1 <= i && i <= n && 1 <= j && j <= n) {
                    if (!rows.count(i) && !cols.count(j))
                        covered_rows.insert(i); // only subtract if it was counted in ans
                }
            }
        }

        // Length of this diagonal
        int len;
        if (d <= 0) {
            len = n + d;
        } else {
            len = n - d;
        }

        // Remove points on this diagonal that were included in the initial count
        ans -= (len - covered_rows.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}