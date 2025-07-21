#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> diag1, diag2, rows, cols;
    set<pair<i64, i64>> occupied;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    // Total squares under attack
    i64 attacked = 0;

    // Rows
    attacked += rows.size() * N;

    // Cols
    attacked += cols.size() * N;

    // Diagonals (x - y)
    for (auto d : diag1) {
        i64 cnt = 0;
        if (-N < d && d < N) {
            cnt = N - abs(d);
        }
        attacked += cnt;
    }

    // Anti-diagonals (x + y)
    for (auto s : diag2) {
        i64 cnt = 0;
        if (2 <= s && s <= 2 * N) {
            if (s <= N + 1)
                cnt = s - 1;
            else
                cnt = 2 * N + 1 - s;
        }
        attacked += cnt;
    }

    // Subtract overlapping cells (they were counted multiple times)
    // Overlap between row and column
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0)
                attacked--;
        }
    }

    // Overlap with diagonal and anti-diagonal
    for (auto [x, y] : occupied) {
        if (diag1.count(x - y)) attacked--;
        if (diag2.count(x + y)) attacked--;
    }

    // Overlap between diagonal and row/column
    for (auto x : rows) {
        for (auto d : diag1) {
            i64 y = x - d;
            if (1 <= y && y <= N && occupied.count({x, y}) == 0)
                attacked--;
        }
    }

    for (auto y : cols) {
        for (auto d : diag1) {
            i64 x = d + y;
            if (1 <= x && x <= N && occupied.count({x, y}) == 0)
                attacked--;
        }
    }

    // Overlap between anti-diagonal and row/column
    for (auto x : rows) {
        for (auto s : diag2) {
            i64 y = s - x;
            if (1 <= y && y <= N && occupied.count({x, y}) == 0)
                attacked--;
        }
    }

    for (auto y : cols) {
        for (auto s : diag2) {
            i64 x = s - y;
            if (1 <= x && x <= N && occupied.count({x, y}) == 0)
                attacked--;
        }
    }

    // Overlap between diagonal and anti-diagonal
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d2 + d1) / 2;
            i64 y = d2 - x;
            if ((d2 + d1) % 2 == 0 && 1 <= x && x <= N && 1 <= y && y <= N &&
                occupied.count({x, y}) == 0)
                attacked--;
        }
    }

    // Total empty squares minus attacked ones
    i64 total_empty = N * N - M;
    cout << total_empty - attacked << "\n";

    return 0;
}