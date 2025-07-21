#include <bits/stdc++.h>
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

    i64 total_captured = 0;

    // Rows
    total_captured += rows.size() * N;
    // Columns
    total_captured += cols.size() * N;
    // Diagonals (i+j)
    for (auto d : diag1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        total_captured += max_x - min_x + 1;
    }
    // Diagonals (i-j)
    for (auto d : diag2) {
        i64 min_x = max(1LL, 1 - d);
        i64 max_x = min(N, N - d);
        total_captured += max_x - min_x + 1;
    }

    // Inclusion-exclusion adjustments
    // Rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }
    // Rows and diag1 (i+j)
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }
    // Rows and diag2 (i-j)
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }
    // Columns and diag1 (i+j)
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }
    // Columns and diag2 (i-j)
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }
    // Diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 r = (d1 + d2) / 2;
            i64 c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }

    // Triple intersections
    // Rows, columns, and diag1
    for (auto r : rows) {
        for (auto c : cols) {
            i64 d1 = r + c;
            if (diag1.count(d1) && occupied.count({r, c}) == 0) {
                total_captured += 1;
            }
        }
    }
    // Rows, columns, and diag2
    for (auto r : rows) {
        for (auto c : cols) {
            i64 d2 = r - c;
            if (diag2.count(d2) && occupied.count({r, c}) == 0) {
                total_captured += 1;
            }
        }
    }
    // Rows, diag1, and diag2
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N) {
                i64 d2 = r - c;
                if (diag2.count(d2) && occupied.count({r, c}) == 0) {
                    total_captured += 1;
                }
            }
        }
    }
    // Columns, diag1, and diag2
    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N) {
                i64 d2 = r - c;
                if (diag2.count(d2) && occupied.count({r, c}) == 0) {
                    total_captured += 1;
                }
            }
        }
    }

    // Quadruple intersection
    for (auto r : rows) {
        for (auto c : cols) {
            i64 d1 = r + c;
            i64 d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2) && occupied.count({r, c}) == 0) {
                total_captured -= 1;
            }
        }
    }

    i64 total_safe = N * N - total_captured - M;
    cout << total_safe << "\n";

    return 0;
}