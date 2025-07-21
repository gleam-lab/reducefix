#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    set<pair<i64, i64>> pieces;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        pieces.insert({a[i], b[i]});
    }

    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }

    i64 forbidden = 0;

    // Rows and columns
    forbidden += rows.size() * N;
    forbidden += cols.size() * N;
    forbidden -= rows.size() * cols.size();

    // Diagonals (type 1: a + b = constant)
    forbidden += diag1.size() * N;
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_max < x_min) continue;
        forbidden -= (x_max - x_min + 1);
    }

    // Diagonals (type 2: a - b = constant)
    forbidden += diag2.size() * N;
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_max < x_min) continue;
        forbidden -= (x_max - x_min + 1);
    }

    // Intersection of rows and type 1 diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                forbidden += 1;
            }
        }
    }

    // Intersection of rows and type 2 diagonals
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                forbidden += 1;
            }
        }
    }

    // Intersection of columns and type 1 diagonals
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                forbidden += 1;
            }
        }
    }

    // Intersection of columns and type 2 diagonals
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = c + d;
            if (r >= 1 && r <= N) {
                forbidden += 1;
            }
        }
    }

    // Intersection of type 1 and type 2 diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    forbidden += 1;
                }
            }
        }
    }

    // Subtract intersections counted multiple times
    // Intersection of rows, columns, and type 1 diagonals
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                forbidden -= 2;
            }
            if (diag2.count(r - c)) {
                forbidden -= 2;
            }
        }
    }

    // Intersection of rows, columns, type 1, and type 2 diagonals
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                forbidden += 1;
            }
        }
    }

    i64 total = N * N;
    i64 safe = total - forbidden + pieces.size();
    cout << safe << "\n";

    return 0;
}