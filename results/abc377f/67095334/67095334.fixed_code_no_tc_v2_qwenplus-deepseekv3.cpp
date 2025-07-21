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

    int total = N * N - M;
    int unsafe = 0;

    // Calculate unsafe squares due to rows and columns
    unsafe += rows.size() * N + cols.size() * N - rows.size() * cols.size();

    // Calculate unsafe squares due to diagonals (i+j)
    for (auto d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        unsafe += len;
    }

    // Calculate unsafe squares due to diagonals (i-j)
    for (auto d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        unsafe += len;
    }

    // Calculate intersections between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            int c = d - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }

    // Calculate intersections between cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            int r = d - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    // Calculate intersections between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            int c = r - d;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
    }

    // Calculate intersections between cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            int r = d + c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    // Calculate intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                int r = (d1 + d2) / 2;
                int c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    unsafe++;
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