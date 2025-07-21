#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 row_count = rows.size();
    i64 col_count = cols.size();
    i64 diag1_count = diag1.size();
    i64 diag2_count = diag2.size();

    // Calculate total squares covered by rows, cols, diag1, diag2
    i64 total_forbidden = row_count * N + col_count * N - row_count * col_count;

    // Add squares covered by diag1
    i64 diag1_squares = 0;
    for (i64 s : diag1) {
        i64 min_xy = max(1LL, s - N);
        i64 max_xy = min(N, s - 1);
        if (min_xy > max_xy) continue;
        diag1_squares += (max_xy - min_xy + 1);
    }
    total_forbidden += diag1_squares;

    // Add squares covered by diag2
    i64 diag2_squares = 0;
    for (i64 d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (min_x > max_x) continue;
        diag2_squares += (max_x - min_x + 1);
    }
    total_forbidden += diag2_squares;

    // Subtract squares counted in both diag1 and rows/cols
    for (i64 s : diag1) {
        for (i64 r : rows) {
            i64 c = s - r;
            if (c >= 1 && c <= N) {
                total_forbidden--;
            }
        }
        for (i64 c : cols) {
            i64 r = s - c;
            if (r >= 1 && r <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract squares counted in both diag2 and rows/cols
    for (i64 d : diag2) {
        for (i64 r : rows) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                total_forbidden--;
            }
        }
        for (i64 c : cols) {
            i64 r = c + d;
            if (r >= 1 && r <= N) {
                total_forbidden--;
            }
        }
    }

    // Subtract squares counted in both diag1 and diag2
    for (i64 s : diag1) {
        for (i64 d : diag2) {
            if ((s + d) % 2 != 0) continue;
            i64 x = (s + d) / 2;
            i64 y = (s - d) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                total_forbidden--;
            }
        }
    }

    // Add back the occupied squares which were subtracted multiple times
    total_forbidden += M;

    // The answer is N*N - total_forbidden, but we need to ensure we don't count occupied squares as safe
    i64 answer = N * N - total_forbidden;
    cout << answer << "\n";

    return 0;
}