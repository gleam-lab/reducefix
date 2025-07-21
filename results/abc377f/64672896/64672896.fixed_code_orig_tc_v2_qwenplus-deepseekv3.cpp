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

    i64 attacked = 0;

    // Attacked by rows
    for (i64 r : rows) {
        attacked += N;
    }

    // Attacked by columns
    for (i64 c : cols) {
        attacked += N;
    }

    // Attacked by diagonals (a + b)
    for (i64 d : diag1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (min_x > max_x) continue;
        attacked += (max_x - min_x + 1);
    }

    // Attacked by diagonals (a - b)
    for (i64 d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (min_x > max_x) continue;
        attacked += (max_x - min_x + 1);
    }

    // Subtract overlaps between rows and columns
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract overlaps between rows and diagonals (a + b)
    for (i64 r : rows) {
        for (i64 d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract overlaps between rows and diagonals (a - b)
    for (i64 r : rows) {
        for (i64 d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract overlaps between columns and diagonals (a + b)
    for (i64 c : cols) {
        for (i64 d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Subtract overlaps between columns and diagonals (a - b)
    for (i64 c : cols) {
        for (i64 d : diag2) {
            i64 r = c + d;
            if (r >= 1 && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Add back overlaps between rows, columns, and both diagonals (intersection of all)
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                attacked += 1;
            }
        }
    }

    // Ensure occupied squares are counted only once
    i64 total_attacked = attacked - M;
    i64 total_safe = N * N - total_attacked;

    cout << total_safe << "\n";

    return 0;
}