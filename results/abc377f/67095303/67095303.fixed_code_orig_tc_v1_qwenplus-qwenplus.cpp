#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t N;
    int M;
    cin >> N >> M;

    set<int64_t> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j
    set<pair<int64_t, int64_t>> points;

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        points.insert({a, b});
    }

    // Total unoccupied squares
    int64_t total_squares = N * N;
    int64_t blocked = 0;

    // Count total threatened squares without overlap
    map<pair<int64_t, char>, int64_t> covered;

    auto add_threatened = [&](int64_t val, char type, int64_t len) {
        auto key = make_pair(val, type);
        if (!covered.count(key)) {
            covered[key] = len;
        }
    };

    // Rows
    for (auto r : rows) add_threatened(r, 'r', N);
    // Columns
    for (auto c : cols) add_threatened(c, 'c', N);
    // Diag1 (i + j)
    for (auto d : diag1) {
        int64_t min_i = max(int64_t(1), d - N);
        int64_t max_i = min(N, d - 1);
        int64_t count = max(int64_t(0), max_i - min_i + 1);
        add_threatened(d, 'd1', count);
    }
    // Diag2 (i - j)
    for (auto d : diag2) {
        int64_t min_i = max(int64_t(1), d + 1);
        int64_t max_i = min(N, N + d);
        int64_t count = max(int64_t(0), max_i - min_i + 1);
        add_threatened(d, 'd2', count);
    }

    // Total threatened squares (union of all lines/diagonals)
    int64_t threat_count = 0;
    for (auto& [key, cnt] : covered) {
        threat_count += cnt;
    }

    // Remove overlaps with other lines/diagonals
    // Subtract overlaps between lines/diagonals
    map<pair<int64_t, int64_t>, int64_t> point_count;
    for (auto r : rows) {
        for (auto c : cols) {
            point_count[{r, c}]++;
        }
        for (auto d : diag1) {
            int64_t j = d - r;
            if (1 <= j && j <= N) {
                point_count[{r, j}]++;
            }
        }
        for (auto d : diag2) {
            int64_t j = r - d;
            if (1 <= j && j <= N) {
                point_count[{r, j}]++;
            }
        }
    }

    for (auto c : cols) {
        for (auto d : diag1) {
            int64_t i = d - c;
            if (1 <= i && i <= N) {
                point_count[{i, c}]++;
            }
        }
        for (auto d : diag2) {
            int64_t i = d + c;
            if (1 <= i && i <= N) {
                point_count[{i, c}]++;
            }
        }
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            int64_t i = (d1 + d2);
            int64_t j = (d1 - d2);
            if (i % 2 == 0 && j % 2 == 0) {
                i /= 2;
                j /= 2;
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    point_count[{i, j}]++;
                }
            }
        }
    }

    // Adjust for overlaps
    int64_t overlap_count = 0;
    for (auto& [p, cnt] : point_count) {
        if (cnt > 1) {
            overlap_count += (cnt - 1);
        }
    }

    // Also include original occupied squares (which were counted as overlaps)
    int64_t answer = total_squares - threat_count + overlap_count - M;
    cout << answer << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}