#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    // Convert to vectors for easier traversal
    vector<i64> rows(rowSet.begin(), rowSet.end());
    vector<i64> cols(colSet.begin(), colSet.end());
    vector<i64> diagSums(diagSumSet.begin(), diagSumSet.end());
    vector<i64> diagDiffs(diagDiffSet.begin(), diagDiffSet.end());

    // Total squares attacked
    i64 attacked = 0;

    // Count attacked cells in rows and columns
    attacked += (i64)rows.size() * N;
    attacked += (i64)cols.size() * N;

    // Subtract overlaps: cells that are both in marked rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            // This cell is counted twice, once in row and once in column
            attacked--;
        }
    }

    // Count attacked cells on diagonal sums (x + y = constant)
    for (auto s : diagSums) {
        i64 low = max(1LL, s - N);
        i64 high = min(N, s - 1);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Count attacked cells on diagonal diffs (x - y = constant)
    for (auto d : diagDiffs) {
        i64 low = max(1LL, d + 1);
        i64 high = min(N, N + d);
        if (low <= high) {
            attacked += high - low + 1;
        }
    }

    // Remove duplicates from diagonal intersections
    for (auto s : diagSums) {
        for (auto d : diagDiffs) {
            // Solve:
            // x + y = s
            // x - y = d
            // => x = (s + d)/2
            // => y = (s - d)/2
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0) {
                i64 x = (s + d) / 2;
                i64 y = (s - d) / 2;
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    // This point was double-counted in both diagonals
                    attacked--;
                }
            }
        }
    }

    // Remove duplicates from row-diagonal overlaps
    for (auto r : rows) {
        for (auto s : diagSums) {
            i64 y = s - r;
            if (1 <= y && y <= N) {
                attacked--; // Already counted in row
            }
        }
        for (auto d : diagDiffs) {
            i64 y = r - d;
            if (1 <= y && y <= N) {
                attacked--; // Already counted in row
            }
        }
    }

    // Remove duplicates from column-diagonal overlaps
    for (auto c : cols) {
        for (auto s : diagSums) {
            i64 x = s - c;
            if (1 <= x && x <= N) {
                attacked--; // Already counted in column
            }
        }
        for (auto d : diagDiffs) {
            i64 x = d + c;
            if (1 <= x && x <= N) {
                attacked--; // Already counted in column
            }
        }
    }

    // Total available positions
    i64 totalPieces = M;
    i64 occupiedOrAttacked = attacked;
    i64 emptyCells = N * N - totalPieces;
    i64 safePositions = emptyCells - occupiedOrAttacked;

    cout << safePositions << "\n";

    return 0;
}