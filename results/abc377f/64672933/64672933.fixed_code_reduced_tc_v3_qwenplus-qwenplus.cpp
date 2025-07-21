#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    set<i64> rowSet, colSet, diagSumSet, diagDiffSet;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rowSet.insert(a);
        colSet.insert(b);
        diagSumSet.insert(a + b);
        diagDiffSet.insert(a - b);
    }

    // Convert sets to vectors for efficient binary search
    vector<i64> rows(rowSet.begin(), rowSet.end());
    vector<i64> cols(colSet.begin(), colSet.end());
    vector<i64> diagSums(diagSumSet.begin(), diagSumSet.end());
    vector<i64> diagDiffs(diagDiffSet.begin(), diagDiffSet.end());

    // Total squares attacked by existing pieces
    i64 attacked = 0;

    // Rows
    attacked += (i64)rows.size() * N;

    // Columns
    attacked += (i64)cols.size() * N;

    // Diagonal sums (x + y = c)
    for (i64 c : diagSums) {
        i64 low = max(1LL, c - N);
        i64 high = min(N, c - 1);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Diagonal diffs (x - y = c)
    for (i64 c : diagDiffs) {
        i64 low = max(1LL, c + 1);
        i64 high = min(N, N + c);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Subtract overlaps

    // Row and column intersections
    for (i64 r : rows) {
        for (i64 c : cols) {
            // (r,c) is counted in both row and column
            attacked--;
        }
    }

    // Row and diagSum intersections
    for (i64 r : rows) {
        for (i64 s : diagSums) {
            i64 c = s - r;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Row and diagDiff intersections
    for (i64 r : rows) {
        for (i64 d : diagDiffs) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Column and diagSum intersections
    for (i64 c : cols) {
        for (i64 s : diagSums) {
            i64 r = s - c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // Column and diagDiff intersections
    for (i64 c : cols) {
        for (i64 d : diagDiffs) {
            i64 r = d + c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // DiagSum and diagDiff intersections
    for (i64 s : diagSums) {
        for (i64 d : diagDiffs) {
            i64 x = (s + d) / 2;
            i64 y = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N) {
                attacked--;
            }
        }
    }

    // Now subtract the overlapping counts from total attacked
    i64 total = N * N - attacked;
    cout << total << "\n";

    return 0;
}