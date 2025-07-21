#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

// Custom hash function for pairs to be used in unordered_set
struct pair_hash {
    inline size_t operator()(const pair<long long, long long>& p) const {
        // Use a simple combination of hashes; can use more sophisticated if needed
        return (p.first * 1000000007LL + p.second) ^ (p.first >> 32);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<long long, long long>, pair_hash> attacked_positions;

    // Knight move patterns
    const vector<pair<long long, long long>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Insert the piece's position
        attacked_positions.insert({a, b});

        // Check each possible attack direction
        for (const auto& [dx, dy] : knight_moves) {
            long long x = a + dx;
            long long y = b + dy;

            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_positions.insert({x, y});
            }
        }
    }

    // Total grid size is N*N
    // Subtract number of positions that are either occupied or under attack
    long long total_squares = N * N;
    cout << (total_squares - static_cast<long long>(attacked_positions.size())) << endl;

    return 0;
}