#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols;
    set<pair<long long, long long>> diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        rows.insert(a);
        cols.insert(b);
        diag1.insert({a + b, a}); // Store diagonal key and row to avoid collision
        diag2.insert({a - b, a}); // Store anti-diagonal key and row to avoid collision
    }

    // Total number of cells not in any attacked line
    long long total = N * N;
    total -= rows.size() * N; // Rows
    total -= cols.size() * N; // Columns

    // Subtract diagonals (diag1: x+y = c)
    total -= diag1.size() * N;
    // Subtract anti-diagonals (diag2: x-y = c)
    total -= diag2.size() * N;

    // Add back over-subtracted intersections:
    // Row-Column intersections
    total += rows.size() * cols.size();
    // Row-Diag1 intersections
    for (auto r : rows) {
        for (auto [d, _] : diag1) {
            // Each diag1 line has multiple points, count how many in this row
            long long y = r;
            long long x = d - y;
            if (1 <= x && x <= N) total++;
        }
    }
    // Row-Diag2 intersections
    for (auto r : rows) {
        for (auto [d, _] : diag2) {
            long long y = r;
            long long x = d + y;
            if (1 <= x && x <= N) total++;
        }
    }
    // Column-Diag1 intersections
    for (auto c : cols) {
        for (auto [d, _] : diag1) {
            long long x = c;
            long long y = d - x;
            if (1 <= y && y <= N) total++;
        }
    }
    // Column-Diag2 intersections
    for (auto c : cols) {
        for (auto [d, _] : diag2) {
            long long x = c;
            long long y = x - d;
            if (1 <= y && y <= N) total++;
        }
    }
    // Diag1-Diag2 intersections
    for (auto [d1, _] : diag1) {
        for (auto [d2, __] : diag2) {
            // Solve:
            // x + y = d1
            // x - y = d2
            long long x = (d1 + d2) / 2;
            long long y = d1 - x;
            if (x >= 1 && x <= N && y >= 1 && y <= N) total++;
        }
    }

    // Subtract triple overlaps (Row-Col-Diag1 etc.)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) total--;
            if (diag2.count(r - c)) total--;
        }
    }

    // Subtract four-way overlap
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) total++;
        }
    }

    cout << total << endl;

    return 0;
}