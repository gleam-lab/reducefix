#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares under attack
    long long attacked = 0;

    // Rows and columns contribute N squares each, but subtract overlaps
    attacked += (long long)rows.size() * N; // All squares in occupied rows
    attacked += (long long)cols.size() * N; // All squares in occupied columns

    // Diagonals: a + b = s -> number of points on that diagonal is N if s ranges from 2 to 2N
    for (auto& d : diag1) {
        // Number of points on diagonal a + b = d
        int count = d <= N + 1 ? d - 1 : 2 * N + 1 - d;
        attacked += count;
    }

    for (auto& d : diag2) {
        // Number of points on diagonal a - b = d
        int count = d >= 0 ? min(N - d, N) : min(N + d, N);
        attacked += count;
    }

    // Inclusion-Exclusion: subtract overcounts

    // Intersections: Row & Column
    for (auto r : rows) {
        for (auto c : cols) {
            --attacked; // (r,c) counted twice
        }
    }

    // Intersections: Row & Diag1 (a + b = s)
    for (auto r : rows) {
        for (auto s : diag1) {
            long long b = s - r;
            if (1 <= b && b <= N) {
                --attacked;
            }
        }
    }

    // Intersections: Row & Diag2 (a - b = d)
    for (auto r : rows) {
        for (auto d : diag2) {
            long long b = r - d;
            if (1 <= b && b <= N) {
                --attacked;
            }
        }
    }

    // Intersections: Column & Diag1 (a + b = s)
    for (auto c : cols) {
        for (auto s : diag1) {
            long long a = s - c;
            if (1 <= a && a <= N) {
                --attacked;
            }
        }
    }

    // Intersections: Column & Diag2 (a - b = d)
    for (auto c : cols) {
        for (auto d : diag2) {
            long long a = d + c;
            if (1 <= a && a <= N) {
                --attacked;
            }
        }
    }

    // Intersections: Diag1 & Diag2 => Solve system:
    // a + b = s
    // a - b = d
    // Solution: a = (s + d)/2, b = (s - d)/2
    for (auto s : diag1) {
        for (auto d : diag2) {
            if ((s + d) % 2 != 0 || (s - d) % 2 != 0) continue;
            long long a = (s + d) / 2;
            long long b = (s - d) / 2;
            if (1 <= a && a <= N && 1 <= b && b <= N) {
                --attacked;
            }
        }
    }

    // Intersections of all three: row, col, diag1/diag2
    for (auto r : rows) {
        for (auto c : cols) {
            long long s = r + c;
            long long d = r - c;
            if (diag1.count(s) && diag2.count(d)) {
                --attacked; // (r,c) counted in both diag1 and diag2
            }
        }
    }

    // Total empty squares where piece can be placed
    long long totalEmpty = N * N - M;
    long long safePositions = totalEmpty - attacked;

    cout << safePositions << endl;

    return 0;
}