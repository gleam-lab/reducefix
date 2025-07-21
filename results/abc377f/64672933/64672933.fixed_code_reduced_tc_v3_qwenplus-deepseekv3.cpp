#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 row_count = rows.size();
    i64 col_count = cols.size();
    i64 diag1_count = diag1.size();
    i64 diag2_count = diag2.size();

    // Calculate squares covered by rows, cols, diag1, diag2
    i64 unsafe = row_count * N + col_count * N - row_count * col_count;

    // Calculate for diag1 (i+j = k)
    for (i64 k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max < x_min) continue;
        unsafe += x_max - x_min + 1;
    }

    // Calculate for diag2 (i-j = k)
    for (i64 k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max < x_min) continue;
        unsafe += x_max - x_min + 1;
    }

    // Subtract overlaps between diag1 and rows/cols
    for (i64 k : diag1) {
        for (i64 r : rows) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                if (occupied.count({r, c}) == 0) {
                    unsafe--;
                }
            }
        }
        for (i64 c : cols) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                if (occupied.count({r, c}) == 0) {
                    unsafe--;
                }
            }
        }
    }

    // Subtract overlaps between diag2 and rows/cols
    for (i64 k : diag2) {
        for (i64 r : rows) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                if (occupied.count({r, c}) == 0) {
                    unsafe--;
                }
            }
        }
        for (i64 c : cols) {
            i64 r = c + k;
            if (r >= 1 && r <= N) {
                if (occupied.count({r, c}) == 0) {
                    unsafe--;
                }
            }
        }
    }

    // Intersections between diag1 and diag2
    for (i64 k1 : diag1) {
        for (i64 k2 : diag2) {
            i64 x = (k1 + k2) / 2;
            i64 y = (k1 - k2) / 2;
            if ((k1 + k2) % 2 == 0 && (k1 - k2) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= N) {
                if (occupied.count({x, y}) == 0) {
                    unsafe--;
                }
            }
        }
    }

    i64 safe = N * N - unsafe;
    cout << safe << "\n";

    return 0;
}