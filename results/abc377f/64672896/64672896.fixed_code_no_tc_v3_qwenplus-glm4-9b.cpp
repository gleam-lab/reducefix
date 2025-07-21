#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    vector<pair<i64, i64>> rows(N + 1), cols(N + 1), rs(N + 1), ds1(N + 1), ds2(N + 1);
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        rows[a].push_back(b);
        cols[b].push_back(a);
        rs[a].push_back(b);
        ds1[a].push_back(b + a);
        ds2[a].push_back(b - a);
    }

    // Helper function to count the number of unique attacks on a line
    auto count_attacks = [&](vector<pair<i64, i64>>& line) -> i64 {
        sort(line.begin(), line.end());
        i64 count = 0;
        for (auto& p : line) {
            if (p.first != p.second) count++;
        }
        return count;
    };

    // Count unique attacks on each line
    i64 row_attacks = count_attacks(rows);
    i64 col_attacks = count_attacks(cols);
    i64 rs_attacks = count_attacks(rs);
    i64 ds1_attacks = count_attacks(ds1);
    i64 ds2_attacks = count_attacks(ds2);

    // Subtract the number of unique attacks from the total number of cells
    i64 safe_cells = N * N - (row_attacks + col_attacks + rs_attacks + ds1_attacks + ds2_attacks);

    cout << safe_cells << '\n';

    return 0;
}