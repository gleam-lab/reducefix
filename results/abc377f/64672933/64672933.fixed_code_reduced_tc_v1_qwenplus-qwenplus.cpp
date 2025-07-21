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

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rowSet.insert(a);
        colSet.insert(b);
        diagSumSet.insert(a + b);
        diagDiffSet.insert(a - b);
    }

    // Convert sets to vectors for easy iteration
    vector<i64> rows(rowSet.begin(), rowSet.end());
    vector<i64> cols(colSet.begin(), colSet.end());
    vector<i64> diagSums(diagSumSet.begin(), diagSumSet.end());
    vector<i64> diagDiffs(diagDiffSet.begin(), diagDiffSet.end());

    // Count attacked squares using inclusion-exclusion

    // Step 1: Count total attacked cells by rows, cols, diagonals
    i64 attacked = 0;

    attacked += (i64)rows.size() * N; // Rows
    attacked += (i64)cols.size() * N; // Columns
    for (i64 s : diagSums) {
        i64 lo = max(1LL, s - N + 1);
        i64 hi = min(N, s - 1);
        if (lo <= hi) attacked += hi - lo + 1;
    }
    for (i64 d : diagDiffs) {
        i64 lo = max(1LL, d + 1);
        i64 hi = min(N, N + d - 1);
        if (lo <= hi) attacked += hi - lo + 1;
    }

    // Step 2: Subtract overcounts (intersections of lines)

    // Row x Col
    for (i64 r : rows) {
        for (i64 c : cols) {
            attacked--;
        }
    }

    // Row x DiagSum
    for (i64 r : rows) {
        for (i64 s : diagSums) {
            i64 c = s - r;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Row x DiagDiff
    for (i64 r : rows) {
        for (i64 d : diagDiffs) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Col x DiagSum
    for (i64 c : cols) {
        for (i64 s : diagSums) {
            i64 r = s - c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // Col x DiagDiff
    for (i64 c : cols) {
        for (i64 d : diagDiffs) {
            i64 r = d + c;
            if (1 <= r && r <= N) {
                attacked--;
            }
        }
    }

    // DiagSum x DiagDiff
    for (i64 s : diagSums) {
        for (i64 d : diagDiffs) {
            if ((s + d) % 2 != 0) continue;
            i64 r = (s + d) / 2;
            i64 c = s - r;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                attacked--;
            }
        }
    }

    // Step 3: Add back triple overlaps (Row x Col x Diag)
    for (i64 r : rows) {
        for (i64 c : cols) {
            i64 s = r + c;
            i64 d = r - c;
            bool inDiagSum = (lower_bound(diagSums.begin(), diagSums.end(), s) != diagSums.end() &&
                              diagSums[lower_bound(diagSums.begin(), diagSums.end(), s) - diagSums.begin()] == s);
            bool inDiagDiff = (lower_bound(diagDiffs.begin(), diagDiffs.end(), d) != diagDiffs.end() &&
                               diagDiffs[lower_bound(diagDiffs.begin(), diagDiffs.end(), d) - diagDiffs.begin()] == d);
            if (inDiagSum || inDiagDiff) {
                attacked++;
            }
        }
    }

    // Finally, subtract the exact positions of the M pieces (they are already included in attacked)
    attacked -= M;

    i64 totalEmpty = N * N - M;
    i64 safePositions = totalEmpty - attacked;

    cout << safePositions << "\n";

    return 0;
}