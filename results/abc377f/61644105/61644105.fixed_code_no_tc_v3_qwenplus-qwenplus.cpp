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
        diag1.emplace(a - b, a + b); // Store both to uniquely identify the point
        diag2.emplace(a + b, a - b);
    }

    long long totalEmpty = N * N - M;
    long long attacked = 0;

    // Rows and columns
    attacked += (long long)rows.size() * N;
    attacked += (long long)cols.size() * N;

    // Diagonals (a - b = constant)
    attacked += (long long)diag1.size() * N;

    // Anti-diagonals (a + b = constant)
    attacked += (long long)diag2.size() * N;

    // Now subtract over-counted squares

    // Intersections: row & column
    for (long long r : rows) {
        for (long long c : cols) {
            attacked--;
        }
    }

    // Intersections: row & diagonal1 (a - b = constant)
    for (long long r : rows) {
        for (auto [d, sum] : diag1) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Intersections: row & anti-diagonal (a + b = constant)
    for (long long r : rows) {
        for (auto [s, d] : diag2) {
            long long c = s - r;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Intersections: column & diagonal1 (a - b = constant)
    for (long long c : cols) {
        for (auto [d, sum] : diag1) {
            long long r = d + c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // Intersects: column & anti-diagonal (a + b = constant)
    for (long long c : cols) {
        for (auto [s, d] : diag2) {
            long long r = s - c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // Intersects: diagonal1 & anti-diagonal
    for (auto [d, sum] : diag1) {
        for (auto [s, tmp] : diag2) {
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Subtract all overlaps that were double-counted
    cout << totalEmpty - attacked << endl;

    return 0;
}