#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>

using namespace std;

// Custom hash for pair<int, int>
struct pair_hash {
    inline size_t operator()(const pair<int, int>& v) const {
        return (static_cast<size_t>(v.first) << 32) | v.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, pair_hash> attacked_positions;

    // The 8 possible attack offsets from a knight-like move
    vector<pair<int, int>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Add the piece's position to attacked_positions
        attacked_positions.insert({a, b});

        // For each attack move pattern, mark the corresponding square if it's valid
        for (const auto& [dx, dy] : attack_offsets) {
            int nx = a + dx;
            int ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked_positions.insert({nx, ny});
            }
        }
    }

    // Total number of cells: N * N
    // Subtract the number of attacked positions
    cout << (1LL * N * N - static_cast<long long>(attacked_positions.size())) << '\n';

    return 0;
}