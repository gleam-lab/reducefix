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

    int total_forbidden = 0;

    // Rows and columns
    total_forbidden += rows.size() * N;
    total_forbidden += cols.size() * N;
    total_forbidden -= rows.size() * cols.size();

    // Diagonals type 1 (i + j = d)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;
        total_forbidden += cnt;
    }

    // Diagonals type 2 (i - j = d)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;
        total_forbidden += cnt;
    }

    // Intersections between rows/cols and diag1/diag2
    for (auto r : rows) {
        for (auto d : diag1) {
            int c = d - r;
            if (1 <= c && c <= N) {
                total_forbidden--;
            }
        }
        for (auto d : diag2) {
            int c = r - d;
            if (1 <= c && c <= N) {
                total_forbidden--;
            }
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            int r = d - c;
            if (1 <= r && r <= N) {
                total_forbidden--;
            }
        }
        for (auto d : diag2) {
            int r = c + d;
            if (1 <= r && r <= N) {
                total_forbidden--;
            }
        }
    }

    // Intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int r = (d1 + d2) / 2;
            int c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract the occupied squares (since they are already counted in rows, cols, diags)
    total_forbidden += M;

    int total_safe = N * N - total_forbidden;
    cout << total_safe << endl;
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