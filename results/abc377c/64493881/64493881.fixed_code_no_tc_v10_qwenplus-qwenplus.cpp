#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    const vector<pair<int64_t, int64_t>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark the piece's position
        attacked_or_occupied.insert(a * 1'000'000'000 + b);

        // Generate all positions it can capture
        for (auto [da, db] : attack_offsets) {
            int64_t na = a + da;
            int64_t nb = b + db;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(na * 1'000'000'000 + nb);
            }
        }
    }

    // Total number of cells: N*N
    // Subtract number of attacked or occupied cells
    int64_t total_cells = N * N;
    int64_t forbidden_cells = attacked_or_occupied.size();

    cout << (total_cells - forbidden_cells) << '\n';

    return 0;
}