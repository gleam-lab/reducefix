#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    set<i64> rowSet, colSet, diagSumSet, diagDiffSet;
    vector<array<i64, 2>> pieces(M);

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rowSet.insert(a);
        colSet.insert(b);
        diagSumSet.insert(a + b);
        diagDiffSet.insert(a - b);
    }

    i64 totalAttacked = 0;

    // Count attacked squares by rows
    totalAttacked += (i64)rowSet.size() * N;

    // Count attacked squares by columns
    totalAttacked += (i64)colSet.size() * N;

    // Count attacked squares by diagonal sums (x + y = c)
    for (i64 s : diagSumSet) {
        i64 low = max(1LL, s - N);
        i64 high = min(N, s - 1);
        if (low <= high) {
            totalAttacked += high - low + 1;
        }
    }

    // Count attacked squares by diagonal diffs (x - y = d)
    for (i64 d : diagDiffSet) {
        i64 low = max(1LL, d + 1);
        i64 high = min(N, N + d);
        if (low <= high) {
            totalAttacked += high - low + 1;
        }
    }

    // Subtract overlaps

    // Overlap between rows and columns
    for (auto [a, b] : pieces) {
        if (rowSet.count(a) && colSet.count(b)) {
            totalAttacked -= 1; // overlap at each piece position
        }
    }

    // Overlap between rows and diagonal sums
    for (auto [a, b] : pieces) {
        if (rowSet.count(a) && diagSumSet.count(a + b)) {
            totalAttacked -= 1;
        }
    }

    // Overlap between rows and diagonal diffs
    for (auto [a, b] : pieces) {
        if (rowSet.count(a) && diagDiffSet.count(a - b)) {
            totalAttacked -= 1;
        }
    }

    // Overlap between columns and diagonal sums
    for (auto [a, b] : pieces) {
        if (colSet.count(b) && diagSumSet.count(a + b)) {
            totalAttacked -= 1;
        }
    }

    // Overlap between columns and diagonal diffs
    for (auto [a, b] : pieces) {
        if (colSet.count(b) && diagDiffSet.count(a - b)) {
            totalAttacked -= 1;
        }
    }

    // Overlap between diagonal sums and diagonal diffs
    for (auto [a, b] : pieces) {
        if (diagSumSet.count(a + b) && diagDiffSet.count(a - b)) {
            totalAttacked -= 1;
        }
    }

    // Overlap between all four: already counted as part of previous overlaps
    // So we add back appropriately due to inclusion-exclusion principle

    // Add back 3-way overlaps subtracted too many times
    for (auto [a, b] : pieces) {
        if (rowSet.count(a) && diagSumSet.count(a + b) && diagDiffSet.count(a - b)) {
            totalAttacked += 1;
        }
        if (colSet.count(b) && diagSumSet.count(a + b) && diagDiffSet.count(a - b)) {
            totalAttacked += 1;
        }
    }

    // Subtract 4-way overlaps which were added back twice unnecessarily
    for (auto [a, b] : pieces) {
        if (rowSet.count(a) && colSet.count(b) && diagSumSet.count(a + b) && diagDiffSet.count(a - b)) {
            totalAttacked -= 1;
        }
    }

    i64 totalEmpty = N * N - M;
    i64 answer = totalEmpty - totalAttacked;
    cout << answer << "\n";

    return 0;
}