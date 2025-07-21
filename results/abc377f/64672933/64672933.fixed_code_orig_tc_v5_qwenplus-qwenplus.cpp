#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag_sum, diag_diff;
    set<pair<i64, i64>> occupied;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag_sum.insert(a + b);
        diag_diff.insert(a - b);
        occupied.emplace(a, b);
    }

    // Total number of squares
    i64 total = N * N;

    // Subtract attacked rows
    i64 attacked_rows = rows.size();
    total -= attacked_rows * N;

    // Subtract attacked columns
    i64 attacked_cols = cols.size();
    total -= attacked_cols * N;

    // Subtract attacked diagonal sums
    i64 attacked_diag_sum = diag_sum.size();
    for (i64 s : diag_sum) {
        // Number of points on x+y=s in [1,N]x[1,N]
        i64 low = max(1LL, s - N);
        i64 high = min(N, s - 1);
        if (low <= high)
            total -= (high - low + 1);
    }

    // Subtract attacked diagonal diffs
    i64 attacked_diag_diff = diag_diff.size();
    for (i64 d : diag_diff) {
        // Number of points on x-y=d in [1,N]x[1,N]
        i64 low = max(1LL, d + 1);
        i64 high = min(N, N + d);
        if (low <= high)
            total -= (high - low + 1);
    }

    // Add back overlaps: row+col
    for (i64 r : rows) {
        for (i64 c : cols) {
            total += 1; // Overlap removed twice, add once
        }
    }

    // Add back overlaps: row+diag_sum
    for (i64 r : rows) {
        for (i64 s : diag_sum) {
            i64 c = s - r;
            if (c >= 1 && c <= N)
                total += 1;
        }
    }

    // Add back overlaps: row+diag_diff
    for (i64 r : rows) {
        for (i64 d : diag_diff) {
            i64 c = r - d;
            if (c >= 1 && c <= N)
                total += 1;
        }
    }

    // Add back overlaps: col+diag_sum
    for (i64 c : cols) {
        for (i64 s : diag_sum) {
            i64 r = s - c;
            if (r >= 1 && r <= N)
                total += 1;
        }
    }

    // Add back overlaps: col+diag_diff
    for (i64 c : cols) {
        for (i64 d : diag_diff) {
            i64 r = d + c;
            if (r >= 1 && r <= N)
                total += 1;
        }
    }

    // Add back overlaps: diag_sum+diag_diff
    for (i64 s : diag_sum) {
        for (i64 d : diag_diff) {
            i64 r = (s + d) / 2;
            i64 c = s - r;
            if ((s + d) % 2 == 0 && r >= 1 && c >= 1 && r <= N && c <= N)
                total += 1;
        }
    }

    // Subtract overlaps of three or more categories (over-added)

    // Subtract triple overlaps: row+col+diag_sum
    for (i64 r : rows) {
        for (i64 c : cols) {
            i64 s = r + c;
            if (diag_sum.count(s))
                total -= 1;
        }
    }

    // Subtract triple overlaps: row+col+diag_diff
    for (i64 r : rows) {
        for (i64 c : cols) {
            i64 d = r - c;
            if (diag_diff.count(d))
                total -= 1;
        }
    }

    // Subtract triple overlaps: row+diag_sum+diag_diff
    for (i64 r : rows) {
        for (i64 s : diag_sum) {
            for (i64 d : diag_diff) {
                i64 c = s - r;
                if (c == r - d && c >= 1 && c <= N)
                    total -= 1;
            }
        }
    }

    // Subtract triple overlaps: col+diag_sum+diag_diff
    for (i64 c : cols) {
        for (i64 s : diag_sum) {
            for (i64 d : diag_diff) {
                i64 r = s - c;
                if (r == d + c && r >= 1 && r <= N)
                    total -= 1;
            }
        }
    }

    // Subtract quadruple overlaps
    for (i64 r : rows) {
        for (i64 c : cols) {
            i64 s = r + c;
            i64 d = r - c;
            if (diag_sum.count(s) && diag_diff.count(d))
                total += 1;
        }
    }

    // Now remove occupied cells from the final count
    for (auto [a, b] : occupied) {
        // Check if (a,b) is in the calculated safe area
        if (!rows.count(a) && !cols.count(b) &&
            !diag_sum.count(a + b) && !diag_diff.count(a - b)) {
            // It was counted as safe but it's not empty
            total -= 1;
        }
    }

    cout << max(0LL, total) << '\n';

    return 0;
}