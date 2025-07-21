#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // Use a hash to represent (a, b) as a single integer: a * N + b
    // This is memory and time efficient for large N up to 1e9

    vector<pair<int64_t, int64_t>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark current piece's position
        attacked_or_occupied.insert(a * N + b);

        for (const auto& [dx, dy] : deltas) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(na * N + nb);
            }
        }
    }

    // Total number of cells: N * N
    // Subtract number of attacked or occupied cells
    int64_t total_cells = N * N;
    int64_t forbidden_cells = attacked_or_occupied.size();
    int64_t result = total_cells - forbidden_cells;

    cout << result << "\n";

    return 0;
}