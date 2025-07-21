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
    int ans = safe_rows * safe_cols;

    // For diag1 (i + j = d)
    for (int d : diag1) {
        int i_min = max(1LL, d - N);
        int i_max = min(N, d - 1);
        int cnt = i_max - i_min + 1;

        set<int> affected_rows;
        for (int i : rows) {
            if (d - i >= 1 && d - i <= N) {
                affected_rows.insert(i);
            }
        }
        set<int> affected_cols;
        for (int j : cols) {
            if (d - j >= 1 && d - j <= N) {
                affected_cols.insert(d - j);
            }
        }

        int total_affected = affected_rows.size() + affected_cols.size();
        for (int i : affected_rows) {
            if (affected_cols.count(i)) {
                total_affected--;
            }
        }

        cnt -= affected_rows.size();
        cnt -= affected_cols.size();
        cnt += total_affected;
        ans -= cnt;
    }

    // For diag2 (i - j = d)
    for (int d : diag2) {
        int i_min = max(1LL, 1 + d);
        int i_max = min(N, N + d);
        int cnt = i_max - i_min + 1;

        set<int> affected_rows;
        for (int i : rows) {
            if (i - d >= 1 && i - d <= N) {
                affected_rows.insert(i);
            }
        }
        set<int> affected_cols;
        for (int j : cols) {
            if (j + d >= 1 && j + d <= N) {
                affected_cols.insert(j + d);
            }
        }

        int total_affected = affected_rows.size() + affected_cols.size();
        for (int i : affected_rows) {
            if (affected_cols.count(i)) {
                total_affected--;
            }
        }

        cnt -= affected_rows.size();
        cnt -= affected_cols.size();
        cnt += total_affected;
        ans -= cnt;
    }

    // Now, handle intersections between diag1 and diag2
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (!rows.count(i) && !cols.count(j)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}