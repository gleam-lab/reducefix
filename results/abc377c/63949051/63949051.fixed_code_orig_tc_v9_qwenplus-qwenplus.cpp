#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store all occupied or threatened positions
    unordered_set<long long> attacked;

    vector<pair<long long, long long>> knights(M);
    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        knights[i] = {x, y};
        // Add the knight's position (to avoid placing there)
        attacked.insert((x - 1) * N + (y - 1));
    }

    // Offsets for knight moves (dx, dy)
    const vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // For each knight, mark all squares it can attack
    for (const auto& pos : knights) {
        long long x = pos.first;
        long long y = pos.second;
        for (const auto& move : moves) {
            long long nx = x + move.first;
            long long ny = y + move.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                // Convert to flat index and add to set
                attacked.insert((nx - 1) * N + (ny - 1));
            }
        }
    }

    // Total squares: N*N minus the number of attacked/occupied squares
    cout << (u_int64_t)(N) * (u_int64_t)(N) - (long long)attacked.size() << "\n";

    return 0;
}