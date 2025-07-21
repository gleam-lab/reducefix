#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diags1, diags2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags1.insert(x + y);
        diags2.insert(x - y);
    }

    int ans = n * n - rows.size() - cols.size();

    for (auto diag1 : diags1) {
        int count = 0;
        for (auto row : rows) {
            if (diag1 - row >= 1 && diag1 - row <= n) {
                count++;
            }
        }
        ans -= count;
    }

    for (auto diag2 : diags2) {
        int count = 0;
        for (auto col : cols) {
            if (diag2 + col >= 1 && diag2 + col <= n) {
                count++;
            }
        }
        ans -= count;
    }

    cout << ans << endl;

    return 0;
}