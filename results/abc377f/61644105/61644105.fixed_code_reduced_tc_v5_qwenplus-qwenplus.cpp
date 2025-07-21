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

    // Total number of empty squares
    long long total_empty = N * N - M;

    // Count how many unique squares are covered by any of the threat lines
    long long total_covered = 0;

    // For each row, it threatens N squares
    total_covered += (long long)rows.size() * N;

    // For each column, it threatens N squares
    total_covered += (long long)cols.size() * N;

    // For each diag1 (a+b), it threatens (min(a+b-1, N*2 - (a+b)+1)) squares
    for (auto s : diag1) {
        long long count;
        if (s <= N + 1)
            count = s - 1;
        else
            count = 2 * N + 1 - s;
        total_covered += count;
    }

    // For each diag2 (a-b), it threatens (N - abs(s)) squares
    for (auto d : diag2) {
        long long count = N - abs(d);
        total_covered += count;
    }

    // Inclusion-Exclusion Principle

    // Row & Column intersections
    for (auto r : rows)
        for (auto c : cols)
            total_covered -= 1;  // Each intersection is double-counted once

    // Row & Diag1: diag1 = r + b => b = diag1 - r
    for (auto r : rows)
        for (auto s : diag1)
            if (s - r >= 1 && s - r <= N)
                total_covered -= 1;

    // Row & Diag2: diag2 = r - b => b = r - diag2
    for (auto r : rows)
        for (auto d : diag2) {
            long long b = r - d;
            if (b >= 1 && b <= N)
                total_covered -= 1;
        }

    // Col & Diag1: diag1 = a + c => a = diag1 - c
    for (auto c : cols)
        for (auto s : diag1) {
            long long a = s - c;
            if (a >= 1 && a <= N)
                total_covered -= 1;
        }

    // Col & Diag2: diag2 = a - c => a = diag2 + c
    for (auto c : cols)
        for (auto d : diag2) {
            long long a = d + c;
            if (a >= 1 && a <= N)
                total_covered -= 1;
        }

    // Diag1 & Diag2: Solve a+b=s and a-b=d => a=(s+d)/2, b=(s-d)/2
    for (auto s : diag1)
        for (auto d : diag2) {
            if ((s + d) % 2 != 0) continue;
            long long a = (s + d) / 2;
            long long b = (s - d) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N)
                total_covered -= 1;
        }

    // Triple overlaps (Row & Col & Diag1), etc.
    for (auto r : rows)
        for (auto c : cols) {
            long long s = r + c;
            long long d = r - c;
            if (diag1.count(s) && diag2.count(d))
                total_covered += 1;
        }

    for (auto r : rows)
        for (auto s : diag1) {
            long long c = s - r;
            long long d = r - c;
            if (c >= 1 && c <= N && diag2.count(d))
                total_covered += 1;
        }

    for (auto c : cols)
        for (auto s : diag1) {
            long long a = s - c;
            long long d = a - c;
            if (a >= 1 && a <= N && diag2.count(d))
                total_covered += 1;
        }

    for (auto r : rows)
        for (auto d : diag2) {
            long long c = r - d;
            long long s = r + c;
            if (c >= 1 && c <= N && diag1.count(s))
                total_covered += 1;
        }

    for (auto c : cols)
        for (auto d : diag2) {
            long long a = d + c;
            long long s = a + c;
            if (a >= 1 && a <= N && diag1.count(s))
                total_covered += 1;
        }

    for (auto s : diag1)
        for (auto d : diag2) {
            if ((s + d) % 2 != 0) continue;
            long long a = (s + d) / 2;
            long long b = (s - d) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N && rows.count(a) && cols.count(b))
                total_covered += 1;
        }

    // Quadruple overlap: subtract back triple-overlaps which were added too many times
    for (auto r : rows)
        for (auto c : cols) {
            long long s = r + c;
            long long d = r - c;
            if (diag1.count(s) && diag2.count(d))
                total_covered -= 1;
        }

    // Final answer: total empty squares minus those threatened
    cout << total_empty - total_covered << endl;

    return 0;
}