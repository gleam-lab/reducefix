#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    set<pair<i64, i64>> occupied;
    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares under attack
    i64 attacked = 0;

    // Count all squares in attacked rows
    attacked += rows.size() * N;

    // Count all squares in attacked columns
    attacked += cols.size() * N;

    // Count all squares in attacked diagonals of type x+y=c
    for (auto d : diag1) {
        // Number of points on diagonal x+y=d in grid [1,N]x[1,N]
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        attacked += (hi - lo + 1);
    }

    // Count all squares in attacked diagonals of type x-y=c
    for (auto d : diag2) {
        if (d >= 0) {
            i64 lo = max(1LL, d + 1);
            i64 hi = min(N, N + d);
            attacked += (hi - lo + 1);
        } else {
            i64 lo = max(1LL, -d + 1);
            i64 hi = min(N, N + d);
            attacked += (hi - lo + 1);
        }
    }

    // Subtract overlaps

    // Rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0)
                attacked -= 1; // double counted
        }
    }

    // Rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0)
                attacked -= 1;
        }
    }

    // Rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0)
                attacked -= 1;
        }
    }

    // Cols and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0)
                attacked -= 1;
        }
    }

    // Cols and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0)
                attacked -= 1;
        }
    }

    // Diag1 and diag2 intersections
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                x >= 1 && x <= N && y >= 1 && y <= N &&
                occupied.count({x, y}) == 0) {
                attacked -= 1;
            }
        }
    }

    // Subtract overcounted occupied cells
    for (auto [x, y] : occupied) {
        bool in_row = rows.count(x);
        bool in_col = cols.count(y);
        bool in_d1 = diag1.count(x + y);
        bool in_d2 = diag2.count(x - y);

        // Count how many sets this point was included in
        i64 cnt = in_row + in_col + in_d1 + in_d2;
        attacked -= (cnt - 1); // should be counted once, not `cnt` times
    }

    i64 total_empty = N * N - M;
    cout << total_empty - attacked << "\n";

    return 0;
}