#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, sum_diags, diff_diags;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        sum_diags.insert(a + b);
        diff_diags.insert(a - b);
    }

    i64 forbidden = 0;

    // Rows
    forbidden += rows.size() * N;

    // Columns
    forbidden += cols.size() * N;

    // Sum diagonals (i + j = k)
    for (i64 k : sum_diags) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max < x_min) continue;
        forbidden += x_max - x_min + 1;
    }

    // Difference diagonals (i - j = k)
    for (i64 k : diff_diags) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max < x_min) continue;
        forbidden += x_max - x_min + 1;
    }

    // Overlaps between rows and columns
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (sum_diags.count(r + c) && diff_diags.count(r - c)) {
                forbidden -= 3; // counted in row, column, sum, and diff diagonals: 4 times, but overlaps are 3 extra
            } else if (sum_diags.count(r + c) || diff_diags.count(r - c)) {
                forbidden -= 1; // counted in row, column, and one diagonal: 3 times, overlaps are 1 extra
            }
        }
    }

    // Overlaps between rows and sum diagonals
    for (i64 r : rows) {
        for (i64 k : sum_diags) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && diff_diags.count(r - c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between columns and sum diagonals
    for (i64 c : cols) {
        for (i64 k : sum_diags) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && diff_diags.count(r - c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between rows and difference diagonals
    for (i64 r : rows) {
        for (i64 k : diff_diags) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                if (cols.count(c) && sum_diags.count(r + c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between columns and difference diagonals
    for (i64 c : cols) {
        for (i64 k : diff_diags) {
            i64 r = c + k;
            if (r >= 1 && r <= N) {
                if (rows.count(r) && sum_diags.count(r + c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between sum and difference diagonals
    set<pair<i64, i64>> intersections;
    for (i64 k1 : sum_diags) {
        for (i64 k2 : diff_diags) {
            if ((k1 + k2) % 2 != 0) continue;
            i64 r = (k1 + k2) / 2;
            i64 c = (k1 - k2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    forbidden -= intersections.size();

    // Overlaps between rows, columns, sum, and difference diagonals
    for (auto [r, c] : intersections) {
        if (rows.count(r) && cols.count(c)) {
            forbidden += 1;
        }
    }

    // Total safe squares
    i64 total = N * N - forbidden + M; // M pieces are already placed and not considered in forbidden
    cout << total << "\n";

    return 0;
}