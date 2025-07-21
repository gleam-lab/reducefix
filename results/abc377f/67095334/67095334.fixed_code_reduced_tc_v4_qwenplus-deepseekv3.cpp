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

    int unsafe = 0;

    // Count squares attacked by rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections counted twice

    // Count squares attacked by diagonals (i+j=d and i-j=d)
    for (int d : diag1) {
        int min_i, max_i;
        if (d <= N + 1) {
            min_i = 1;
            max_i = d - 1;
        } else {
            min_i = d - N;
            max_i = N;
        }
        unsafe += (max_i - min_i + 1);
    }

    for (int d : diag2) {
        int min_i, max_i;
        if (d >= 0) {
            min_i = 1 + d;
            max_i = N;
        } else {
            min_i = 1;
            max_i = N + d;
        }
        unsafe += (max_i - min_i + 1);
    }

    // Subtract intersections of diagonals with rows and columns that were counted twice
    for (int r : rows) {
        for (int d : diag1) {
            int c = d - r;
            if (1 <= c && c <= N) {
                if (pieces.find({r, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
        for (int d : diag2) {
            int c = r - d;
            if (1 <= c && c <= N) {
                if (pieces.find({r, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    for (int c : cols) {
        for (int d : diag1) {
            int r = d - c;
            if (1 <= r && r <= N) {
                if (pieces.find({r, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
        for (int d : diag2) {
            int r = c + d;
            if (1 <= r && r <= N) {
                if (pieces.find({r, c}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract intersections of diagonals with each other that were counted four times
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= i && i <= N && 1 <= j && j <= N) {
                if (pieces.find({i, j}) == pieces.end()) {
                    unsafe--;
                }
            }
        }
    }

    // Total safe squares = total empty squares - unsafe squares
    int total_empty = N * N - M;
    int safe = total_empty - unsafe;
    cout << max(safe, 0LL) << endl;
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