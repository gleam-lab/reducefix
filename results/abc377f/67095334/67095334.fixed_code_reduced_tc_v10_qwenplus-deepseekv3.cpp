#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
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
    int unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * (N - rows.size());

    // Diagonals (i+j)
    for (auto d : diag1) {
        int min_j = max(1LL, d - N);
        int max_j = min(N, d - 1);
        if (min_j > max_j) continue;
        int cnt = max_j - min_j + 1;
        unsafe += cnt;
    }

    // Diagonals (i-j)
    for (auto d : diag2) {
        int min_j = max(1LL, 1 - d);
        int max_j = min(N, N - d);
        if (min_j > max_j) continue;
        int cnt = max_j - min_j + 1;
        unsafe += cnt;
    }

    // Intersections between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            int j = d - r;
            if (1 <= j && j <= N && cols.find(j) == cols.end()) {
                unsafe--;
            }
        }
    }

    // Intersections between columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            int i = d - c;
            if (1 <= i && i <= N && rows.find(i) == rows.end()) {
                unsafe--;
            }
        }
    }

    // Intersections between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            int j = r - d;
            if (1 <= j && j <= N && cols.find(j) == cols.end()) {
                unsafe--;
            }
        }
    }

    // Intersections between columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            int i = d + c;
            if (1 <= i && i <= N && rows.find(i) == rows.end()) {
                unsafe--;
            }
        }
    }

    // Intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                        unsafe--;
                    }
                }
            }
        }
    }

    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}