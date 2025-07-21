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
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 total = N * N;
    i64 attacked = 0;

    // Rows and columns
    i64 unique_rows = rows.size();
    i64 unique_cols = cols.size();
    attacked += unique_rows * N;
    attacked += unique_cols * N;
    attacked -= unique_rows * unique_cols; // Intersection of rows and columns

    // Diagonals (i + j = constant)
    for (auto d : diag1) {
        i64 cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Anti-diagonals (i - j = constant)
    for (auto d : diag2) {
        i64 cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N) {
                attacked -= 1;
            }
        }
        for (auto d2 : diag2) {
            i64 c = r - d2;
            if (c >= 1 && c <= N) {
                attacked -= 1;
            }
        }
    }

    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N) {
                attacked -= 1;
            }
        }
        for (auto d2 : diag2) {
            i64 r = d2 + c;
            if (r >= 1 && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Add intersections between diagonals and anti-diagonals that were subtracted twice
    set<pair<i64, i64>> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    intersections.insert({r, c});
                }
            }
        }
    }
    attacked += intersections.size();

    // Subtract intersections between rows/columns and both diagonals/anti-diagonals that were added back
    for (auto r : rows) {
        for (auto c : cols) {
            if (intersections.count({r, c})) {
                attacked -= 1;
            }
        }
    }

    // The safe squares are total squares minus attacked squares plus occupied squares (since they are already occupied)
    i64 safe = total - attacked + M;
    cout << safe << endl;

    return 0;
}