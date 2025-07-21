#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    unordered_set<int64_t> attacked_or_occupied;
    // We'll use a unique key for each (a,b) pair: a * P + b where P is a large prime
    const int64_t P = 1000000007;

    vector<pair<int64_t, int64_t>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Mark current piece position
        attacked_or_occupied.insert(a * P + b);

        // Mark all squares that this piece can attack
        for (const auto& [dx, dy] : knight_moves) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_or_occupied.insert(na * P + nb);
            }
        }
    }

    // Total number of cells = N * N
    // Subtract the number of attacked or occupied cells
    int64_t total_cells = N * N;
    int64_t blocked_cells = attacked_or_occupied.size();

    cout << (total_cells - blocked_cells) << endl;

    return 0;
}