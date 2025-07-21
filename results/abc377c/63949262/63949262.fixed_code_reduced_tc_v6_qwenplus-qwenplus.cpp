#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Define a hash function for pairs of integers
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 16); // Combine the two hashes
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<pair<long long, long long>, pair_hash> attacked_positions;

    vector<pair<long long, long long>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Add the position of the current piece
        attacked_positions.insert({a, b});

        // Check each possible knight move from this piece
        for (const auto& [dx, dy] : knight_moves) {
            long long nx = a + dx;
            long long ny = b + dy;

            // Only add positions that are within the board bounds
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked_positions.insert({nx, ny});
            }
        }
    }

    // Total squares on the board is N*N
    unsigned long long total_squares = static_cast<unsigned long long>(N) * static_cast<unsigned long long>(N);

    // The number of squares that are either occupied or under attack
    unsigned long long unavailable_squares = attacked_positions.size();

    // The number of safe squares is total - unavailable
    cout << total_squares - unavailable_squares << "\n";

    return 0;
}