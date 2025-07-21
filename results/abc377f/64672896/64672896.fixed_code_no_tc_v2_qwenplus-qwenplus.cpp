#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rowSet, colSet, diagSumSet, diagDiffSet;
    vector<i64> aVec, bVec;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rowSet.insert(a);
        colSet.insert(b);
        diagSumSet.insert(a + b);
        diagDiffSet.insert(a - b);
        aVec.push_back(a);
        bVec.push_back(b);
    }

    // Total number of cells
    i64 total = N * N;

    // Remove all cells in occupied rows
    i64 captured = N * rowSet.size();

    // Remove all cells in occupied columns
    captured += N * colSet.size();

    // Remove diagonals: sum diagonal (x + y = c)
    // For each diagonal value s = x + y, count how many valid (x,y) exist within [1,N]x[1,N]
    // This is equivalent to the number of integer solutions (x, y) such that:
    // 1 <= x <= N, 1 <= y <= N and x + y = s
    // So we iterate over all s values from diagSumSet and calculate overlap with grid.
    for (i64 s : diagSumSet) {
        i64 low = max(1LL, s - N);
        i64 high = min(N, s - 1);
        if (low <= high) {
            captured += high - low + 1;
        }
    }

    // Remove anti-diagonals: difference diagonal (x - y = d)
    // x - y = d => x = y + d
    // 1 <= y <= N
    // 1 <= y + d <= N => max(1 - d, 1) <= y <= min(N - d, N)
    for (i64 d : diagDiffSet) {
        i64 low = max(1LL, 1 - d);
        i64 high = min(N, N - d);
        if (low <= high) {
            captured += high - low + 1;
        }
    }

    // Now subtract overlaps: cells that were counted more than once

    // Cells in both a row and column
    for (i64 a : rowSet) {
        for (i64 b : colSet) {
            bool found = false;
            for (i64 i = 0; i < M; ++i) {
                if (a == aVec[i] && b == bVec[i]) {
                    found = true;
                    break;
                }
            }
            if (found) continue;
            --captured; // subtract one duplicate
        }
    }

    // Cells in both a row and sum diagonal
    for (i64 a : rowSet) {
        for (i64 s : diagSumSet) {
            i64 b = s - a;
            if (b >= 1 && b <= N) {
                bool found = false;
                for (i64 i = 0; i < M; ++i) {
                    if (a == aVec[i] && b == bVec[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) --captured;
            }
        }
    }

    // Cells in both a column and sum diagonal
    for (i64 b : colSet) {
        for (i64 s : diagSumSet) {
            i64 a = s - b;
            if (a >= 1 && a <= N) {
                bool found = false;
                for (i64 i = 0; i < M; ++i) {
                    if (a == aVec[i] && b == bVec[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) --captured;
            }
        }
    }

    // Cells in both a row and difference diagonal
    for (i64 a : rowSet) {
        for (i64 d : diagDiffSet) {
            i64 b = a - d;
            if (b >= 1 && b <= N) {
                bool found = false;
                for (i64 i = 0; i < M; ++i) {
                    if (a == aVec[i] && b == bVec[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) --captured;
            }
        }
    }

    // Cells in both a column and difference diagonal
    for (i64 b : colSet) {
        for (i64 d : diagDiffSet) {
            i64 a = d + b;
            if (a >= 1 && a <= N) {
                bool found = false;
                for (i64 i = 0; i < M; ++i) {
                    if (a == aVec[i] && b == bVec[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) --captured;
            }
        }
    }

    // Cells in both sum and difference diagonals
    for (i64 s : diagSumSet) {
        for (i64 d : diagDiffSet) {
            // Solve:
            // x + y = s
            // x - y = d
            // => x = (s + d) / 2
            // => y = (s - d) / 2
            if ((s + d) % 2 != 0 || (s - d) % 2 != 0) continue;
            i64 x = (s + d) / 2;
            i64 y = (s - d) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                bool found = false;
                for (i64 i = 0; i < M; ++i) {
                    if (x == aVec[i] && y == bVec[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) --captured;
            }
        }
    }

    // Subtract cells already covered by multiple sets
    cout << N * N - captured << "\n";

    return 0;
}