#include <bits/stdc++.h>

using namespace std;

#define MAX_M 1000

long long N, M;
int a[MAX_M + 1], b[MAX_M + 1];

int main() {
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    unordered_set<int> rows, cols;
    unordered_set<long long> diag1, diag2; // diag1: a - b, diag2: a + b

    for (int i = 0; i < M; i++) {
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] - b[i]);
        diag2.insert(a[i] + b[i]);
    }

    long long unsafe_rows = rows.size();
    long long unsafe_cols = cols.size();
    long long unsafe_diag1 = diag1.size();
    long long unsafe_diag2 = diag2.size();

    // Total unsafe squares without considering overlaps
    long long total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;

    // Add unsafe squares from diag1 (a - b = constant)
    for (long long d : diag1) {
        // Calculate the number of squares (i, j) where i - j = d
        long long i_min = max(1LL, 1 + d);
        long long i_max = min(N, N + d);
        if (i_min > i_max) continue;
        total_unsafe += (i_max - i_min + 1);
    }

    // Add unsafe squares from diag2 (a + b = constant)
    for (long long s : diag2) {
        // Calculate the number of squares (i, j) where i + j = s
        long long i_min = max(1LL, s - N);
        long long i_max = min(N, s - 1);
        if (i_min > i_max) continue;
        total_unsafe += (i_max - i_min + 1);
    }

    // Subtract overlaps between rows and diag1
    for (long long r : rows) {
        for (long long d : diag1) {
            long long j = r - d;
            if (j >= 1 && j <= N) {
                total_unsafe--;
            }
        }
    }

    // Subtract overlaps between rows and diag2
    for (long long r : rows) {
        for (long long s : diag2) {
            long long j = s - r;
            if (j >= 1 && j <= N) {
                total_unsafe--;
            }
        }
    }

    // Subtract overlaps between cols and diag1
    for (long long c : cols) {
        for (long long d : diag1) {
            long long i = c + d;
            if (i >= 1 && i <= N) {
                total_unsafe--;
            }
        }
    }

    // Subtract overlaps between cols and diag2
    for (long long c : cols) {
        for (long long s : diag2) {
            long long i = s - c;
            if (i >= 1 && i <= N) {
                total_unsafe--;
            }
        }
    }

    // Add overlaps between diag1 and diag2
    for (long long d : diag1) {
        for (long long s : diag2) {
            if ((s - d) % 2 != 0) continue;
            long long i = (s + d) / 2;
            long long j = (s - d) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                total_unsafe++;
            }
        }
    }

    // Subtract overlaps between rows, cols, and diag1
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c)) {
                total_unsafe++;
            }
        }
    }

    // Subtract overlaps between rows, cols, and diag2
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag2.count(r + c)) {
                total_unsafe++;
            }
        }
    }

    // Add overlaps between rows, cols, diag1, and diag2
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                total_unsafe--;
            }
        }
    }

    long long total_safe = N * N - total_unsafe;
    printf("%lld\n", total_safe);

    return 0;
}