#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int safe_rows = N - rows.size();
    int safe_cols = N - cols.size();
    int initial_safe = safe_rows * safe_cols;

    // Calculate squares attacked by diagonals not already covered by rows or columns
    // For diag1: i + j = d
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        if (len <= 0) continue;

        int attacked = len;
        // Subtract squares already covered by rows or cols
        for (int i = min_i; i <= max_i; ++i) {
            int j = d - i;
            if (rows.count(i) || cols.count(j)) {
                attacked--;
            }
        }
        initial_safe -= attacked;
    }

    // For diag2: i - j = d
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        if (len <= 0) continue;

        int attacked = len;
        // Subtract squares already covered by rows or cols
        for (int i = min_i; i <= max_i; ++i) {
            int j = i - d;
            if (rows.count(i) || cols.count(j)) {
                attacked--;
            }
        }
        initial_safe -= attacked;
    }

    // Now, add back squares that were subtracted twice (intersection of diag1 and diag2)
    // These are squares (i,j) where both diag1 and diag2 exist for (i,j)
    // So, i + j = d1 and i - j = d2 => i = (d1 + d2)/2, j = (d1 - d2)/2
    // Only if both i and j are integers and within bounds
    set<PII> intersections;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0 || (d1 - d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (!rows.count(i) && !cols.count(j)) {
                    intersections.insert({i, j});
                }
            }
        }
    }
    initial_safe += intersections.size();

    cout << initial_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}