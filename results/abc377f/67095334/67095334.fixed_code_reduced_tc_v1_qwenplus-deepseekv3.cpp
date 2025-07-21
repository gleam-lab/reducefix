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

    // For diag1: i + j = d
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        if (len <= 0) continue;

        set<int> intersect;
        for (int x : rows) {
            if (1 <= d - x && d - x <= N) {
                intersect.insert(d - x);
            }
        }
        for (int y : cols) {
            if (1 <= d - y && d - y <= N) {
                intersect.insert(y);
            }
        }
        int cnt = len - intersect.size();
        initial_safe -= cnt;
    }

    // For diag2: i - j = d
    for (int d : diag2) {
        int min_j = max(1LL, 1 - d);
        int max_j = min(N, N - d);
        int len = max_j - min_j + 1;
        if (len <= 0) continue;

        set<int> intersect;
        for (int x : rows) {
            if (1 <= x - d && x - d <= N) {
                intersect.insert(x - d);
            }
        }
        for (int y : cols) {
            if (1 <= y + d && y + d <= N) {
                intersect.insert(y);
            }
        }
        int cnt = len - intersect.size();
        initial_safe -= cnt;
    }

    cout << initial_safe << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) {
        solve();
    }

    return 0;
}