#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<uint64_t> occupied;
    auto hash = [](long long x, long long y) {
        return (uint64_t(x) << 32) | uint64_t(y);
    };

    // The 8 possible knight move directions
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        uint64_t pos = hash(a, b);
        if (occupied.insert(pos).second) {
            // Only count unique positions
            continue;
        }
    }

    // Count attack positions
    unordered_set<uint64_t> attacked;
    for (auto it = occupied.begin(); it != occupied.end(); ++it) {
        uint64_t h = *it;
        long long a = h >> 32;
        long long b = h & 0xFFFFFFFF;

        for (const auto& [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                uint64_t target = hash(x, y);
                attacked.insert(target);
            }
        }
    }

    // Remove attacked positions from empty squares
    // Total empty = N*N - number of occupied cells
    // Subtract also the number of attacked cells that are not themselves occupied
    long long total_occupied = occupied.size();
    long long total_attackable_empty = 0;

    for (auto it = attacked.begin(); it != attacked.end(); ++it) {
        if (occupied.count(*it) == 0) {
            ++total_attackable_empty;
        }
    }

    long long total_empty = N * N - total_occupied;
    long long result = total_empty - total_attackable_empty;

    cout << result << endl;

    return 0;
}