#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t N, M;
    cin >> N >> M;

    unordered_set<uint64_t> occupied_positions;

    for (uint64_t i = 0; i < M; ++i) {
        uint64_t x, y;
        cin >> x >> y;
        occupied_positions.insert((x - 1) * N + y);
    }

    uint64_t total_positions = N * N;
    uint64_t valid_positions = total_positions - occupied_positions.size();

    for (const auto& pos : occupied_positions) {
        uint64_t x = (pos / N) + 1;
        uint64_t y = (pos % N) + 1;

        // Check up to 8 possible knight moves
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (const auto& move : moves) {
            int new_x = x + move.first;
            int new_y = y + move.second;
            if (new_x > 0 && new_x <= N && new_y > 0 && new_y <= N) {
                valid_positions++;
            }
        }
    }

    valid_positions /= 2; // Each knight move affects two positions

    cout << valid_positions << endl;

    return 0;
}