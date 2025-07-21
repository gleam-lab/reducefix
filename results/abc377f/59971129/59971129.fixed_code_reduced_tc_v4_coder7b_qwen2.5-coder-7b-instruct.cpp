#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define clr(v, x) memset(v, x, sizeof(v))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int ans = (n - rows.size()) * (n - cols.size());

    rep(d, 1, n) {
        int count = n - abs(n - d);
        if (count == 0) continue;

        // Check vertical captures
        for (auto r : rows) {
            if (r + d <= n && !diag2.count(r + d)) --count;
            if (r - d >= 1 && !diag2.count(r - d)) --count;
        }

        // Check horizontal captures
        for (auto c : cols) {
            if (c + d <= n && !diag1.count(c + d)) --count;
            if (c - d >= 1 && !diag1.count(c - d)) --count;
        }

        ans -= count;
    }

    cout << ans << '\n';

    return 0;
}