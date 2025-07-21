#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> row, col, diag1, diag2; // diag1: i+j, diag2: i-j
    set<pair<int, int>> blocked;     // To avoid counting duplicates

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        row.insert(x);
        col.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
        blocked.insert({x, y});
    }

    int totalCells = N * N;
    int blockedCount = blocked.size();

    // Number of cells in all attacked rows and columns not yet considered
    int rows = row.size();
    int cols = col.size();

    // Total cells attacked via row/column
    int rc_attack = rows * N + cols * N - rows * cols;

    // For diagonals, compute length and subtract overlaps
    auto get_diag_len = [&](int d, bool is_sum) -> int {
        if (is_sum) {
            if (d <= N + 1)
                return d - 1;
            else
                return 2 * N + 1 - d;
        } else {
            d = abs(d);
            return N - d + 1;
        }
    };

    set<int> seen_d1, seen_d2;
    int diag1_cells = 0, diag2_cells = 0;

    for (int d : diag1) {
        diag1_cells += get_diag_len(d, true);
        seen_d1.insert(d);
    }

    for (int d : diag2) {
        diag2_cells += get_diag_len(d, false);
        seen_d2.insert(d);
    }

    // Subtract overlaps: row-col, row-diag1, row-diag2, col-diag1, col-diag2, diag1-diag2

    int overlap_rc = 0;
    for (int r : row) {
        for (int c : col) {
            if (!blocked.count({r, c}))
                overlap_rc++;
        }
    }

    int overlap_r_d1 = 0;
    for (int r : row) {
        for (int d : diag1) {
            int c = d - r;
            if (1 <= c && c <= N && !blocked.count({r, c}))
                overlap_r_d1++;
        }
    }

    int overlap_r_d2 = 0;
    for (int r : row) {
        for (int d : diag2) {
            int c = r - d;
            if (1 <= c && c <= N && !blocked.count({r, c}))
                overlap_r_d2++;
        }
    }

    int overlap_c_d1 = 0;
    for (int c : col) {
        for (int d : diag1) {
            int r = d - c;
            if (1 <= r && r <= N && !blocked.count({r, c}))
                overlap_c_d1++;
        }
    }

    int overlap_c_d2 = 0;
    for (int c : col) {
        for (int d : diag2) {
            int r = d + c;
            if (1 <= r && r <= N && !blocked.count({r, c}))
                overlap_c_d2++;
        }
    }

    int overlap_d1_d2 = 0;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            int r = (d1 + d2);
            int c = (d1 - d2);
            if (r % 2 == 0 && c % 2 == 0) {
                r /= 2;
                c /= 2;
                if (1 <= r && r <= N && 1 <= c && c <= N && !blocked.count({r, c}))
                    overlap_d1_d2++;
            }
        }
    }

    // Inclusion-Exclusion Principle
    int total_attacked = rc_attack + diag1_cells + diag2_cells
                         - overlap_rc - overlap_r_d1 - overlap_r_d2 - overlap_c_d1 - overlap_c_d2 - overlap_d1_d2;

    int answer = totalCells - total_attacked - blockedCount;
    cout << answer << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}