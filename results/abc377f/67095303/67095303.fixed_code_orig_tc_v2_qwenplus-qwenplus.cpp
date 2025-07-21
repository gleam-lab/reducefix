#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
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

    // Step 1: Total safe positions without considering attacks
    long long ans = N * N - M;

    // Step 2: Remove squares attacked by rows and columns
    // Total squares attacked by rows and columns = rows × N + cols × N - rows × cols
    // Because rows × N covers all cells in those rows, same for cols
    // But intersection (cells in both attacked row and column) are double-counted, so subtract rows*cols
    ans -= rows.size() * N + cols.size() * N - rows.size() * cols.size();

    // Step 3: Now consider diagonals

    // Function to return length of diagonal for d = i+j
    auto len_d1 = [&](long long d) -> long long {
        if (d < 1) return 0;
        if (d <= N + 1) return d - 1;
        else return 2 * N + 1 - d;
    };

    // Function to return length of diagonal for d = i-j
    auto len_d2 = [&](long long d) -> long long {
        if (d < -(N - 1) || d > N - 1) return 0;
        return N - abs(d);
    };

    // For each diagonal from diag1
    for (auto d : diag1) {
        long long l = len_d1(d);
        ans -= l;
    }

    // For each diagonal from diag2
    for (auto d : diag2) {
        long long l = len_d2(d);
        ans -= l;
    }

    // Step 4: Add back over-subtracted intersections between diagonals and rows/columns

    // Count overlaps of diag1 with rows and cols
    for (auto d : diag1) {
        for (auto r : rows) {
            long long c = d - r;
            if (c >= 1 && c <= N) ans += 1;
        }
        for (auto c : cols) {
            long long r = d - c;
            if (r >= 1 && r <= N) ans += 1;
        }
    }

    // Count overlaps of diag2 with rows and cols
    for (auto d : diag2) {
        for (auto r : rows) {
            long long c = r - d;
            if (c >= 1 && c <= N) ans += 1;
        }
        for (auto c : cols) {
            long long r = c + d;
            if (r >= 1 && r <= N) ans += 1;
        }
    }

    // Step 5: Add back overlaps between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve system:
            // i + j = d1
            // i - j = d2
            // => i = (d1 + d2)/2
            // => j = (d1 - d2)/2
            if ((d1 + d2) % 2 == 0) {
                long long i = (d1 + d2) / 2;
                long long j = (d1 - d2) / 2;
                if (i >= 1 && i <= N && j >= 1 && j <= N) {
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}