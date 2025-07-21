#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // We'll use a hash to uniquely identify (i,j) pair using a large prime multiplier
    const int64_t PRIME = 1'000'000'007;

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark current piece's position
        attacked_or_occupied.insert(a * PRIME + b);

        // Define relative moves based on the knight-like pattern
        vector<pair<int64_t, int64_t>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto [dx, dy] : directions) {
            int64_t x = a + dx;
            int64_t y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_or_occupied.insert(x * PRIME + y);
            }
        }
    }

    // Total number of cells: N * N
    // Subtract the number of attacked or occupied cells
    int64_t totalCells = N * N;
    int64_t forbiddenCount = attacked_or_occupied.size();
    int64_t result = totalCells - forbiddenCount;

    cout << result << endl;
    return 0;
}