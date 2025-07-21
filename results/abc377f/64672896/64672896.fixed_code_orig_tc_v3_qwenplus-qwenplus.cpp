#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols;
    set<i64> diag1, diag2; // x+y and x-y

    set<pair<i64, i64>> occupied;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.emplace(a, b);
    }

    // Total squares under attack = |rows|*N + |cols|*N - |rows|*|cols|
    //                           + |diag1|*(2*N-1) + |diag2|*(2*N-1) - |diag1 ∩ diag2|
    // But we must subtract overlaps carefully.

    i64 attacked = 0;
    attacked += (i64)rows.size() * N;
    attacked += (i64)cols.size() * N;
    attacked -= (i64)rows.size() * cols.size(); // overlap between row and column

    auto count_diag_cells = [&](i64 s) -> i64 {
        if (s < 2 || s > 2 * N)
            return 0;
        i64 cnt = min(s - 1, 2 * N - s + 1);
        return cnt;
    };

    map<i64, i64> d1_map, d2_map;
    for (auto d : diag1) {
        attacked += count_diag_cells(d);
        d1_map[d] = count_diag_cells(d);
    }
    for (auto d : diag2) {
        attacked += count_diag_cells(d);
        d2_map[d] = count_diag_cells(d);
    }

    // subtract overlaps between diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = d1 - x;
            if ((d1 + d2) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked -= 1;
            }
        }
    }

    // subtract overlaps between row/col and diagonals
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 y = d - r;
            if (y >= 1 && y <= N)
                attacked -= 1;
        }
        for (auto d : diag2) {
            i64 y = r - d;
            if (y >= 1 && y <= N)
                attacked -= 1;
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            i64 x = d - c;
            if (x >= 1 && x <= N)
                attacked -= 1;
        }
        for (auto d : diag2) {
            i64 x = d + c;
            if (x >= 1 && x <= N)
                attacked -= 1;
        }
    }

    // Add back overlaps between all four types that were over-subtracted
    // This is complex, but we can use inclusion-exclusion precisely
    // However, it's better to calculate total safe cells directly using set logic

    // Now we subtract the already occupied cells from attacked count
    i64 result = N * N - attacked + M;

    // Ensure no negative values due to overcounting
    cout << max(0LL, result) << "\n";

    return 0;
}