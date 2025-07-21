#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<long long> rows, cols, diags, anti_diags;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags.insert(a - b);
        anti_diags.insert(a + b);
    }

    long long unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Overlap between rows and columns

    // Diagonals (a - b = constant)
    for (long long d : diags) {
        // Calculate the number of cells in the diagonal d = a - b
        long long min_a = max(1LL, 1 + d);
        long long max_a = min(N, N + d);
        if (max_a >= min_a) {
            unsafe += (max_a - min_a + 1);
        }
    }

    // Anti-diagonals (a + b = constant)
    for (long long s : anti_diags) {
        // Calculate the number of cells in the anti-diagonal s = a + b
        long long min_a = max(1LL, s - N);
        long long max_a = min(N, s - 1);
        if (max_a >= min_a) {
            unsafe += (max_a - min_a + 1);
        }
    }

    // Overlap between diagonals and anti-diagonals
    for (long long d : diags) {
        for (long long s : anti_diags) {
            // Find intersection point (a, b) where a - b = d and a + b = s
            long long a = (d + s) / 2;
            long long b = (s - d) / 2;
            if ((d + s) % 2 == 0 && (s - d) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between rows/columns and diagonals/anti-diagonals
    for (long long r : rows) {
        for (long long d : diags) {
            long long b = r - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
        for (long long s : anti_diags) {
            long long b = s - r;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }

    for (long long c : cols) {
        for (long long d : diags) {
            long long a = c + d;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
        for (long long s : anti_diags) {
            long long a = s - c;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }

    // Total safe squares
    long long total = N * N;
    long long safe = total - unsafe;

    cout << safe << endl;

    return 0;
}