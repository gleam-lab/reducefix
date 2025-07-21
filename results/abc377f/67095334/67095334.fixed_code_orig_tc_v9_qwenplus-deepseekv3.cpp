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

    // Total safe squares not in any row or column
    int safe_squares = (N - rows.size()) * (N - cols.size());

    // Subtract squares on diagonals type 1 (i+j = d) not already in rows or cols
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int total = max_i - min_i + 1;
        int excluded = 0;
        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                excluded++;
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                excluded++;
            }
        }
        safe_squares -= (total - excluded);
    }

    // Subtract squares on diagonals type 2 (i-j = d) not already in rows or cols
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int total = max_i - min_i + 1;
        int excluded = 0;
        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                excluded++;
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                excluded++;
            }
        }
        safe_squares -= (total - excluded);
    }

    // Add back squares that were subtracted twice (on both diagonals)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                        safe_squares++;
                    }
                }
            }
        }
    }

    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}