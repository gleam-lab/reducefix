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

    int total = N * N;
    int attacked = 0;

    // Add rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * (N - rows.size());

    // Add diagonals (i+j = d)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;

        // Subtract squares already counted in rows or columns
        for (auto r : rows) {
            if (d - r >= 1 && d - r <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            if (d - c >= 1 && d - c <= N) {
                cnt--;
            }
        }
        attacked += cnt;
    }

    // Add anti-diagonals (i-j = d)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;

        // Subtract squares already counted in rows or columns
        for (auto r : rows) {
            if (r - d >= 1 && r - d <= N) {
                cnt--;
            }
        }
        for (auto c : cols) {
            if (c + d >= 1 && c + d <= N) {
                cnt--;
            }
        }
        attacked += cnt;
    }

    // Subtract overlaps between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) || cols.count(j)) continue;
                attacked--;
            }
        }
    }

    int safe = total - attacked;
    cout << safe << endl;
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