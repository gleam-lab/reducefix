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
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    // First subtract all squares in attacked rows or columns
    int total = (n - rows.size()) * (n - cols.size());

    // Now subtract the intersections with diagonals that are not already covered by row/col attacks
    auto compute_diag1_len = [&](int d) -> int {
        int lo = max(1LL, d - n);
        int hi = min(n, d - 1);
        return max(0LL, hi - lo + 1);
    };

    auto compute_diag2_len = [&](int d) -> int {
        int lo = max(1LL, 1 + d);
        int hi = min(n, n + d);
        return max(0LL, hi - lo + 1);
    };

    // For each diagonal of type x+y=d
    for (int d : diag1) {
        // Count how many points on this diagonal are already excluded due to attacked rows/columns
        int blocked = 0;
        set<int> seen;

        // Check intersection with attacked rows
        for (int x : rows) {
            int y = d - x;
            if (1 <= y && y <= n && seen.find(x) == seen.end()) {
                seen.insert(x);
                blocked++;
            }
        }

        // Check intersection with attacked columns
        for (int y : cols) {
            int x = d - y;
            if (1 <= x && x <= n && seen.find(x) == seen.end()) {
                seen.insert(x);
                blocked++;
            }
        }

        int diag_len = compute_diag1_len(d);
        total -= (diag_len - blocked);
    }

    // For each diagonal of type x-y=d
    for (int d : diag2) {
        // Count how many points on this diagonal are already excluded due to attacked rows/columns
        int blocked = 0;
        set<int> seen;

        // Check intersection with attacked rows
        for (int x : rows) {
            int y = x - d;
            if (1 <= y && y <= n && seen.find(x) == seen.end()) {
                seen.insert(x);
                blocked++;
            }
        }

        // Check intersection with attacked columns
        for (int y : cols) {
            int x = d + y;
            if (1 <= x && x <= n && seen.find(x) == seen.end()) {
                seen.insert(x);
                blocked++;
            }
        }

        int diag_len = compute_diag2_len(d);
        total -= (diag_len - blocked);
    }

    cout << total << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}