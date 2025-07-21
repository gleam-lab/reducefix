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

    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int diagonal_length = max_i - min_i + 1;
        int unsafe = 0;

        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                unsafe++;
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                unsafe++;
            }
        }
        for (auto d2 : diag2) {
            int i = (d + d2) / 2;
            int j = (d - d2) / 2;
            if ((d + d2) % 2 == 0 && (d - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe++;
            }
        }
        initial_safe -= (diagonal_length - unsafe);
    }

    for (auto d : diag2) {
        int min_j = max(1LL, 1 - d);
        int max_j = min(N, N - d);
        int diagonal_length = max_j - min_j + 1;
        int unsafe = 0;

        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                unsafe++;
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                unsafe++;
            }
        }
        for (auto d1 : diag1) {
            int i = (d1 + d) / 2;
            int j = (d1 - d) / 2;
            if ((d1 + d) % 2 == 0 && (d1 - d) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe++;
            }
        }
        initial_safe -= (diagonal_length - unsafe);
    }

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