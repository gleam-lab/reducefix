#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> h, v, d1, d2;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        h.insert(x);
        v.insert(y);
        d1.insert(x + y);
        d2.insert(x - y);
    }

    // Step 1: Safe area without row/column attack
    long long ans = 1LL * (N - h.size()) * (N - v.size());

    // Step 2: Subtract overlaps with positive diagonals (i + j = d)
    for (int d : d1) {
        set<int> seen_rows;
        for (int x : h) {
            int y = d - x;
            if (1 <= y && y <= N) seen_rows.insert(x);
        }
        for (int y : v) {
            int x = d - y;
            if (1 <= x && x <= N) seen_rows.insert(x);
        }

        // Length of diagonal d within bounds
        int len;
        if (d <= N + 1)
            len = d - 1;
        else
            len = 2 * N + 1 - d;

        ans -= (len - seen_rows.size());
    }

    // Step 3: Subtract overlaps with negative diagonals (i - j = d)
    for (int d : d2) {
        set<int> seen_rows;
        for (int x : h) {
            int y = x - d;
            if (1 <= y && y <= N) seen_rows.insert(x);
        }
        for (int y : v) {
            int x = d + y;
            if (1 <= x && x <= N) seen_rows.insert(x);
        }

        // Length of diagonal d within bounds
        int len;
        if (d >= 0)
            len = N - d;
        else
            len = N + d;

        ans -= (len - seen_rows.size());
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}