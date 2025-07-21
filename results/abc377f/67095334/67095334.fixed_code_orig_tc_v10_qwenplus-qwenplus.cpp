#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    int ans = (N - (int)rows.size()) * (N - (int)cols.size());

    // Process Diag1: i + j = d
    for (int d : diag1) {
        int lo = max(1LL, d - N);
        int hi = min(N, d - 1);
        int len = hi - lo + 1;

        // Count how many of these are already excluded due to rows/cols
        set<int> seen;
        for (int r : rows) {
            int c = d - r;
            if (c >= 1 && c <= N)
                seen.insert(r);
        }
        for (int c : cols) {
            int r = d - c;
            if (r >= 1 && r <= N)
                seen.insert(r);
        }

        ans -= (len - seen.size());
    }

    // Process Diag2: i - j = d
    for (int d : diag2) {
        int lo = max(1LL, d + 1);
        int hi = min(N, N + d);
        int len = hi - lo + 1;

        // Count how many of these are already excluded due to rows/cols
        set<int> seen;
        for (int r : rows) {
            int c = r - d;
            if (c >= 1 && c <= N)
                seen.insert(r);
        }
        for (int c : cols) {
            int r = d + c;
            if (r >= 1 && r <= N)
                seen.insert(r);
        }

        ans -= (len - seen.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}