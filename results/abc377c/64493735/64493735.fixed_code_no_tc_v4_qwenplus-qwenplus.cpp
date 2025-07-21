#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    const int dirs[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Add current piece's position
        attacked_or_occupied.insert(a * 1000000000 + b);

        // Generate all 8 possible attack positions
        for (auto& dir : dirs) {
            int64_t na = a + dir[0];
            int64_t nb = b + dir[1];

            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(na * 1000000000 + nb);
            }
        }
    }

    // Total number of cells is N * N
    // Subtract the number of attacked or occupied cells
    int64_t total_cells = N * N;
    int64_t unavailable = attacked_or_occupied.size();

    cout << (total_cells - unavailable) << '\n';

    return 0;
}