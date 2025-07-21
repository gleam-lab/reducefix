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

    // Calculate safe squares on diagonals not covered by rows or columns
    for (auto d : diag1) {
        int min_ij = max(1LL, d - N);
        int max_ij = min(N, d - 1);
        int length = max_ij - min_ij + 1;
        set<int> covered;
        for (auto r : rows) {
            if (1 <= d - r && d - r <= N) {
                covered.insert(d - r);
            }
        }
        for (auto c : cols) {
            if (1 <= d - c && d - c <= N) {
                covered.insert(c);
            }
        }
        initial_safe += (length - covered.size());
    }

    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int length = max_i - min_i + 1;
        set<int> covered;
        for (auto r : rows) {
            if (1 <= r - d && r - d <= N) {
                covered.insert(r - d);
            }
        }
        for (auto c : cols) {
            if (1 <= c + d && c + d <= N) {
                covered.insert(c);
            }
        }
        initial_safe += (length - covered.size());
    }

    // Subtract overlaps between diag1 and diag2 that were counted twice
    set<PII> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    if (rows.find(i) == rows.end() && cols.find(j) == rows.end()) {
                        intersections.insert({i, j});
                    }
                }
            }
        }
    }
    initial_safe -= intersections.size();

    cout << initial_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}