#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    // Set to store all occupied squares and squares under attack
    unordered_set<int64_t> attacked_or_occupied;

    // Directions for knight moves
    vector<pair<int64_t, int64_t>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Store the position itself as occupied
        attacked_or_occupied.insert(a * (N + 2) + b);

        // Mark all 8 possible attacked squares
        for (auto [dx, dy] : directions) {
            int64_t x = a + dx;
            int64_t y = b + dy;

            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_or_occupied.insert(x * (N + 2) + y);
            }
        }
    }

    // Total number of squares is N*N
    // Subtract the number of attacked or occupied squares
    cout << (N * N) - static_cast<int64_t>(attacked_or_occupied.size()) << "\n";

    return 0;
}