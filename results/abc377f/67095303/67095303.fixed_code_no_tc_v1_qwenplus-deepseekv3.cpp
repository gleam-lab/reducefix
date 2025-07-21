#include<bits/stdc++.h>
#define int long long
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

    // Unsafe due to rows and columns
    unsafe += rows.size() * N + cols.size() * N - rows.size() * cols.size();

    // Unsafe due to diagonals (i+j = d)
    for (auto d : diag1) {
        int i_min = max(1LL, d - N);
        int i_max = min(N, d - 1);
        int len = i_max - i_min + 1;
        unsafe += len;
    }

    // Unsafe due to diagonals (i-j = d)
    for (auto d : diag2) {
        int i_min = max(1LL, 1 + d);
        int i_max = min(N, N + d);
        int len = i_max - i_min + 1;
        unsafe += len;
    }

    // Subtract intersections between rows/cols and diagonals
    for (auto d : diag1) {
        set<int> intersections;
        for (auto r : rows) {
            int c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert(r * N + c);
            }
        }
        for (auto c : cols) {
            int r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert(r * N + c);
            }
        }
        unsafe -= intersections.size();
    }

    for (auto d : diag2) {
        set<int> intersections;
        for (auto r : rows) {
            int c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert(r * N + c);
            }
        }
        for (auto c : cols) {
            int r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert(r * N + c);
            }
        }
        unsafe -= intersections.size();
    }

    // Subtract intersections between diag1 and diag2
    set<int> diag_intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    diag_intersections.insert(i * N + j);
                }
            }
        }
    }
    unsafe -= diag_intersections.size();

    // Add back the squares covered by all three: rows, cols, and diagonals (already subtracted twice)
    for (auto r : rows) {
        for (auto c : cols) {
            int d1 = r + c;
            int d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) {
                unsafe++;
            }
        }
    }

    int safe = total - unsafe;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}