#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
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
    // Sum diagonals
    for (i64 s : sum_diags) {
        i64 x_min = max(1LL, s - N);
        i64 x_max = min(N, s - 1);
        if (x_max >= x_min) {
            forbidden += x_max - x_min + 1;
        }
    }
    // Difference diagonals
    for (i64 d : diff_diags) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_max >= x_min) {
            forbidden += x_max - x_min + 1;
        }
    }

    // Overlaps between rows and columns
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (sum_diags.count(r + c) || diff_diags.count(r - c)) {
                forbidden -= 1;
            }
        }
    }

    // Overlaps between rows and sum diagonals
    for (i64 r : rows) {
        for (i64 s : sum_diags) {
            i64 c = s - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diff_diags.count(r - c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between rows and difference diagonals
    for (i64 r : rows) {
        for (i64 d : diff_diags) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || sum_diags.count(r + c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between columns and sum diagonals
    for (i64 c : cols) {
        for (i64 s : sum_diags) {
            i64 r = s - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diff_diags.count(r - c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between columns and difference diagonals
    for (i64 c : cols) {
        for (i64 d : diff_diags) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || sum_diags.count(r + c)) {
                    forbidden -= 1;
                }
            }
        }
    }

    // Overlaps between sum and difference diagonals
    for (i64 s : sum_diags) {
        for (i64 d : diff_diags) {
            if ((s + d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = (s - d) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    if (rows.count(r) || cols.count(c)) {
                        forbidden -= 1;
                    }
                }
            }
        }
    }

    // Overlaps between rows, columns, sum diagonals, and difference diagonals
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (sum_diags.count(r + c) && diff_diags.count(r - c)) {
                forbidden += 1;
            }
        }
    }

    i64 total_squares = N * N;
    i64 safe_squares = total_squares - forbidden + M; // Adding M because existing pieces were subtracted but they are already occupied
    cout << safe_squares << "\n";

    return 0;
}