#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // Count of unique lines
    long long R = rows.size();
    long long C = cols.size();
    long long D1 = diag1.size();
    long long D2 = diag2.size();

    // Inclusion-Exclusion Principle
    long long total_attacked = 0;

    // Single components
    total_attacked += R * N;
    total_attacked += C * N;
    for (long long d : diag1) total_attacked += N - abs(d - (N + 1));
    for (long long d : diag2) total_attacked += N - abs(d);

    // Subtract pairwise overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            if ((r + c) >= 1 && (r + c) <= 2 * N && (r - c) >= -(N - 1) && (r - c) <= (N - 1))
                total_attacked -= 1;
        }
    }

    for (long long r : rows) {
        for (long long d1 : diag1) {
            long long c = d1 - r;
            if (c >= 1 && c <= N)
                total_attacked -= 1;
        }
    }

    for (long long r : rows) {
        for (long long d2 : diag2) {
            long long c = r - d2;
            if (c >= 1 && c <= N)
                total_attacked -= 1;
        }
    }

    for (long long c : cols) {
        for (long long d1 : diag1) {
            long long r = d1 - c;
            if (r >= 1 && r <= N)
                total_attacked -= 1;
        }
    }

    for (long long c : cols) {
        for (long long d2 : diag2) {
            long long r = c + d2;
            if (r >= 1 && r <= N)
                total_attacked -= 1;
        }
    }

    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N)
                total_attacked -= 1;
        }
    }

    // Add back triple overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            long long d1 = r + c;
            long long d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2))
                total_attacked += 1;
        }
    }

    for (long long r : rows) {
        for (long long d1 : diag1) {
            long long c = d1 - r;
            if (cols.count(c)) {
                long long d2 = r - c;
                if (diag2.count(d2))
                    total_attacked += 1;
            }
        }
    }

    for (long long r : rows) {
        for (long long d2 : diag2) {
            long long c = r - d2;
            if (cols.count(c)) {
                long long d1 = r + c;
                if (diag1.count(d1))
                    total_attacked += 1;
            }
        }
    }

    for (long long c : cols) {
        for (long long d1 : diag1) {
            long long r = d1 - c;
            if (rows.count(r)) {
                long long d2 = r - c;
                if (diag2.count(d2))
                    total_attacked += 1;
            }
        }
    }

    for (long long c : cols) {
        for (long long d2 : diag2) {
            long long r = c + d2;
            if (rows.count(r)) {
                long long d1 = r + c;
                if (diag1.count(d1))
                    total_attacked += 1;
            }
        }
    }

    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if (rows.count(r) && cols.count(c))
                total_attacked += 1;
        }
    }

    // Subtract quadruple overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            long long d1 = r + c;
            long long d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2))
                total_attacked -= 1;
        }
    }

    long long total_squares = N * N;
    long long occupied = M;
    long long safe_squares = total_squares - occupied - total_attacked;

    cout << safe_squares << endl;

    return 0;
}