#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    int attacked_rows = rows.size();
    int attacked_cols = cols.size();
    int attacked_diag1 = diag1.size();
    int attacked_diag2 = diag2.size();

    // Total squares under attack by rows or columns or diagonals
    int total_attacked = attacked_rows * N + attacked_cols * N - attacked_rows * attacked_cols;

    // Now, subtract the intersections with diagonals to avoid double counting
    // For each diagonal in diag1, calculate how many squares are not already covered by rows or cols
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int diag_length = max_i - min_i + 1;

        // Count squares in this diagonal that are not in any attacked row or column
        int overlap = 0;
        for (int i = min_i; i <= max_i; ++i) {
            int j = d - i;
            if (rows.count(i) || cols.count(j)) {
                overlap++;
            }
        }
        total_attacked += (diag_length - overlap);
    }

    // For each diagonal in diag2, similarly
    for (int d : diag2) {
        int min_i = max(1LL, 1 - d);
        int max_i = min(N, N - d);
        int diag_length = max_i - min_i + 1;

        int overlap = 0;
        for (int i = min_i; i <= max_i; ++i) {
            int j = i - d;
            if (rows.count(i) || cols.count(j)) {
                overlap++;
            }
        }
        total_attacked += (diag_length - overlap);
    }

    // Now, some squares might be counted in both diag1 and diag2, leading to over-subtraction
    // We need to add back the squares that are in both diagonals and not covered by rows or cols
    // For each piece, its intersection is already counted, but we need to find intersections not covered by any piece
    // Instead, find all intersections of diag1 and diag2, and subtract those that are not covered by rows or cols
    // But this is complex, so another approach is to iterate over all pieces and check their diagonals

    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (!rows.count(i) && !cols.count(j)) {
                    total_attacked--;
                }
            }
        }
    }

    int total_squares = N * N;
    int safe_squares = total_squares - total_attacked;
    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}