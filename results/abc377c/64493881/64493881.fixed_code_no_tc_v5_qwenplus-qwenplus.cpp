#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // We'll use a hash to map (a, b) to a unique key: a * 1e9 + b

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark current piece's position
        attacked_or_occupied.insert(a * 1000000000LL + b);

        // Define the 8 possible target positions where this piece can attack
        vector<pair<int64_t, int64_t>> deltas = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto& delta : deltas) {
            int64_t na = a + delta.first;
            int64_t nb = b + delta.second;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(na * 1000000000LL + nb);
            }
        }
    }

    // Total number of cells: N*N
    // Subtract the number of attacked or occupied cells
    int64_t total_cells = N * N;
    int64_t forbidden_cells = attacked_or_occupied.size();

    cout << (total_cells - forbidden_cells) << '\n';

    return 0;
}