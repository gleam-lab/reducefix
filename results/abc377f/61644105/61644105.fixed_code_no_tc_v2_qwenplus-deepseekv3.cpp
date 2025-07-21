#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pieces(M);
    unordered_set<long long> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    long long total = N * N;
    long long unsafe = 0;

    // Unsafe squares due to rows, cols, diag1, diag2
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe += diag1.size() * N;
    unsafe += diag2.size() * N;

    // Overlap between row and col
    unsafe -= rows.size() * cols.size();

    // Overlap between row and diag1
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = d - r;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between row and diag2
    for (long long r : rows) {
        for (long long d : diag2) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between col and diag1
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = d - c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between col and diag2
    for (long long c : cols) {
        for (long long d : diag2) {
            long long r = c + d;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Overlap between diag1 and diag2
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Triple overlaps
    for (auto [a, b] : pieces) {
        // row, col, diag1
        if (rows.count(a) && cols.count(b) && diag1.count(a + b)) {
            unsafe++;
        }
        // row, col, diag2
        if (rows.count(a) && cols.count(b) && diag2.count(a - b)) {
            unsafe++;
        }
        // row, diag1, diag2
        if (rows.count(a) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe++;
        }
        // col, diag1, diag2
        if (cols.count(b) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe++;
        }
    }

    // Quadruple overlap
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag1.count(a + b) && diag2.count(a - b)) {
            unsafe--;
        }
    }

    long long safe = total - unsafe;
    cout << safe << endl;

    return 0;
}