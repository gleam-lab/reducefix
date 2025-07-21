#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, sum_diags, diff_diags;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        sum_diags.insert(a + b);
        diff_diags.insert(a - b);
        pieces.insert({a, b});
    }

    long long total = N * N;
    long long row_count = rows.size();
    long long col_count = cols.size();
    long long sum_diag_count = sum_diags.size();
    long long diff_diag_count = diff_diags.size();

    total -= row_count * N;
    total -= col_count * N;
    total -= sum_diag_count * (N - abs(1 - (*(sum_diags.begin()))));
    for (auto s : sum_diags) {
        long long min_ij = max(1LL, 1 + s - N);
        long long max_ij = min(N, s - 1);
        if (max_ij >= min_ij) {
            total += (max_ij - min_ij + 1);
        }
    }
    for (auto d : diff_diags) {
        long long min_ij = max(1LL, 1 + d);
        long long max_ij = min(N, N + d);
        if (max_ij >= min_ij) {
            total += (max_ij - min_ij + 1);
        }
    }

    // Inclusion for intersections: row and col, row and sum, row and diff, col and sum, col and diff, sum and diff
    for (auto a : rows) {
        for (auto b : cols) {
            if (sum_diags.find(a + b) != sum_diags.end() && diff_diags.find(a - b) != diff_diags.end()) {
                total += 1;
            }
        }
    }

    for (auto a : rows) {
        for (auto s : sum_diags) {
            long long b = s - a;
            if (b >= 1 && b <= N) {
                if (cols.find(b) != cols.end() && diff_diags.find(a - b) != diff_diags.end()) {
                    total += 1;
                }
            }
        }
    }

    for (auto a : rows) {
        for (auto d : diff_diags) {
            long long b = a - d;
            if (b >= 1 && b <= N) {
                if (cols.find(b) != cols.end() && sum_diags.find(a + b) != sum_diags.end()) {
                    total += 1;
                }
            }
        }
    }

    for (auto b : cols) {
        for (auto s : sum_diags) {
            long long a = s - b;
            if (a >= 1 && a <= N) {
                if (rows.find(a) != rows.end() && diff_diags.find(a - b) != diff_diags.end()) {
                    total += 1;
                }
            }
        }
    }

    for (auto b : cols) {
        for (auto d : diff_diags) {
            long long a = d + b;
            if (a >= 1 && a <= N) {
                if (rows.find(a) != rows.end() && sum_diags.find(a + b) != sum_diags.end()) {
                    total += 1;
                }
            }
        }
    }

    for (auto s : sum_diags) {
        for (auto d : diff_diags) {
            if ((s + d) % 2 == 0) {
                long long a = (s + d) / 2;
                long long b = (s - d) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    if (rows.find(a) != rows.end() && cols.find(b) != cols.end()) {
                        total += 1;
                    }
                }
            }
        }
    }

    // Inclusion for triple intersections: row and col and sum, row and col and diff, row and sum and diff, col and sum and diff
    for (auto a : rows) {
        for (auto b : cols) {
            if (sum_diags.find(a + b) != sum_diags.end()) {
                if (diff_diags.find(a - b) != diff_diags.end()) {
                    total -= 1;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}