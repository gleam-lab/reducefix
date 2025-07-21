#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    set<PII> pieces;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        pieces.insert({a, b});
    }

    int total = N * N - M;
    int unsafe = 0;

    // Unsafe squares due to rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Unsafe squares due to diagonals (i + j = d)
    int diag1_squares = 0;
    for (auto d : diag1) {
        int x_min, x_max, y_min, y_max;
        if (d <= N + 1) {
            x_min = 1;
            x_max = d - 1;
            y_min = d - x_max;
            y_max = d - x_min;
        } else {
            x_min = d - N;
            x_max = N;
            y_min = d - x_max;
            y_max = d - x_min;
        }
        diag1_squares += (x_max - x_min + 1);
    }

    // Unsafe squares due to diagonals (i - j = d)
    int diag2_squares = 0;
    for (auto d : diag2) {
        int x_min, x_max, y_min, y_max;
        if (d >= 0) {
            x_min = 1 + d;
            x_max = N;
            y_min = x_min - d;
            y_max = x_max - d;
        } else {
            x_min = 1;
            x_max = N + d;
            y_min = x_min - d;
            y_max = x_max - d;
        }
        diag2_squares += (x_max - x_min + 1);
    }

    unsafe += diag1_squares + diag2_squares;

    // Subtract overlaps between rows and diag1
    for (auto d : diag1) {
        for (auto r : rows) {
            if (1 <= d - r && d - r <= N) {
                if (pieces.find({r, d - r}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract overlaps between cols and diag1
    for (auto d : diag1) {
        for (auto c : cols) {
            if (1 <= d - c && d - c <= N) {
                if (pieces.find({d - c, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract overlaps between rows and diag2
    for (auto d : diag2) {
        for (auto r : rows) {
            if (1 <= r - d && r - d <= N) {
                if (pieces.find({r, r - d}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract overlaps between cols and diag2
    for (auto d : diag2) {
        for (auto c : cols) {
            if (1 <= d + c && d + c <= N) {
                if (pieces.find({d + c, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract overlaps between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    if (pieces.find({i, j}) == pieces.end()) {
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
    while (_--) {
        solve();
    }

    return 0;
}