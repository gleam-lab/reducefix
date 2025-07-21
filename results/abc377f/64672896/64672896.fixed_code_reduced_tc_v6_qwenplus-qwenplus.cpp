#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, a_diag, m_diag;
    set<pair<i64, i64>> occupied_cells;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        a_diag.insert(a + b);
        m_diag.insert(a - b);
        occupied_cells.insert({a, b});
    }

    // Step 1: Count total threatened cells

    i64 count = 0;

    // Rows and Columns contribute N cells each
    count += (i64)rows.size() * N;
    count += (i64)cols.size() * N;

    // Anti-diagonals
    for (auto d : a_diag) {
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        if (lo <= hi) count += hi - lo + 1;
    }

    // Main diagonals
    for (auto d : m_diag) {
        i64 lo = max(1LL, 1 + d);
        i64 hi = min(N, N + d);
        if (lo <= hi) count += hi - lo + 1;
    }

    // Inclusion-Exclusion starts here

    // Intersections between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            count--; // Overlap at (r, c)
        }
    }

    // Intersections between row and anti-diagonal
    for (auto r : rows) {
        for (auto d : a_diag) {
            i64 c = d - r;
            if (1 <= c && c <= N) count--;
        }
    }

    // Intersections between row and main diagonal
    for (auto r : rows) {
        for (auto d : m_diag) {
            i64 c = r - d;
            if (1 <= c && c <= N) count--;
        }
    }

    // Intersections between column and anti-diagonal
    for (auto c : cols) {
        for (auto d : a_diag) {
            i64 r = d - c;
            if (1 <= r && r <= N) count--;
        }
    }

    // Intersections between column and main diagonal
    for (auto c : cols) {
        for (auto d : m_diag) {
            i64 r = d + c;
            if (1 <= r && r <= N) count--;
        }
    }

    // Intersections between anti-diagonal and main diagonal
    for (auto ad : a_diag) {
        for (auto md : m_diag) {
            i64 r = (ad + md) / 2;
            i64 c = (ad - md) / 2;
            if ((ad + md) % 2 == 0 && (ad - md) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                count--;
            }
        }
    }

    // Subtract overlaps already counted more than once

    // Intersections between row, column, and anti-diagonal
    for (auto r : rows) {
        for (auto c : cols) {
            if (a_diag.count(r + c)) count--;
        }
    }

    // Intersections between row, column, and main diagonal
    for (auto r : rows) {
        for (auto c : cols) {
            if (m_diag.count(r - c)) count--;
        }
    }

    // Intersections between all three: row, anti-diagonal, main diagonal
    for (auto r : rows) {
        i64 ad = r + (1); // Just iterate over all possible c from 1..N
        for (i64 c = 1; c <= N; ++c) {
            if (a_diag.count(r + c) && m_diag.count(r - c)) count--;
        }
    }

    // Now subtract the actual occupied cells (already counted as part of all categories)
    count -= occupied_cells.size();

    // Total empty safe cells = Total - Threatened
    cout << N * N - count << "\n";

    return 0;
}