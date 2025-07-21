#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diagSum, diagDiff;
    vector<pair<i64, i64>> pieces;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.emplace_back(a, b);
        rows.insert(a);
        cols.insert(b);
        diagSum.insert(a + b);
        diagDiff.insert(a - b);
    }

    // Count how many cells lie on any of the forbidden directions
    i64 forbidden = 0;

    // Add all cells on forbidden rows or columns
    forbidden += (i64)rows.size() * N;
    forbidden += (i64)cols.size() * N;

    // Subtract overlap: cells that are both in forbidden rows AND columns
    for (auto r : rows) {
        for (auto c : cols) {
            forbidden--; // because counted twice
        }
    }

    // Add all cells on forbidden diagonals (sum = a + b)
    for (auto s : diagSum) {
        // x + y = s
        i64 y_min = max(1LL, s - N);
        i64 y_max = min(N, s - 1);
        if (y_min <= y_max) {
            forbidden += y_max - y_min + 1;
        }
    }

    // Subtract overlaps between row/col and diagSum
    for (auto [x, y] : pieces) {
        i64 s = x + y;
        i64 y_min = max(1LL, s - N);
        i64 y_max = min(N, s - 1);
        if (y >= y_min && y <= y_max) {
            forbidden--;
        }
    }

    // Add all cells on forbidden anti-diagonals (diff = x - y)
    for (auto d : diagDiff) {
        // x - y = d => x = y + d
        i64 y_min = max(1LL, 1 - d);
        i64 y_max = min(N, N - d);
        if (y_min <= y_max) {
            forbidden += y_max - y_min + 1;
        }
    }

    // Subtract overlaps between row/col and diagDiff
    for (auto [x, y] : pieces) {
        i64 d = x - y;
        i64 y_min = max(1LL, 1 - d);
        i64 y_max = min(N, N - d);
        if (y >= y_min && y <= y_max) {
            forbidden--;
        }
    }

    // Subtract overlaps between diagSum and diagDiff
    for (auto s : diagSum) {
        for (auto d : diagDiff) {
            // Solve:
            // x + y = s
            // x - y = d
            // => x = (s + d)/2, y = (s - d)/2
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0) {
                i64 x = (s + d) / 2;
                i64 y = (s - d) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    forbidden--;
                }
            }
        }
    }

    // Now compute number of valid empty positions
    i64 total_cells = N * N;
    i64 used_cells = M;
    i64 empty_cells = total_cells - used_cells;
    i64 answer = empty_cells - forbidden;

    cout << answer << "\n";

    return 0;
}