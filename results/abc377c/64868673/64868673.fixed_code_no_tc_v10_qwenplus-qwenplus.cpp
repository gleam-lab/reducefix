#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // Set to store all occupied squares and threatened empty squares
    unordered_set<uint64_t> attacked_or_occupied;

    // Lambda to convert (a, b) into a unique 64-bit integer key
    auto encode = [](long long a, long long b) -> uint64_t {
        return ((uint64_t)a << 32) | (uint64_t)b;
    };

    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        uint64_t pos = encode(a, b);
        if (attacked_or_occupied.insert(pos).second) {
            // Mark the current position as occupied
            for (const auto& [dx, dy] : directions) {
                long long x = a + dx;
                long long y = b + dy;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    uint64_t neighbor = encode(x, y);
                    attacked_or_occupied.insert(neighbor); // Mark as threatened
                }
            }
        }
    }

    // Total number of cells: N * N
    // Subtract the number of attacked or occupied cells
    cout << (uint64_t)(N) * (uint64_t)(N) - (uint64_t)attacked_or_occupied.size() << endl;

    return 0;
}