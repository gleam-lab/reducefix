#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Use a set to store positions of all pieces and attacked squares
    unordered_set<long long> piece_positions;
    unordered_set<long long> attacked_squares;

    // Directions for knight-like moves (8 directions)
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        // Store current piece position
        long long pos = (static_cast<long long>(x) << 32) | y;
        piece_positions.insert(pos);

        // Generate attacked squares in all 8 directions
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                long long attack_pos = (static_cast<long long>(nx) << 32) | ny;
                attacked_squares.insert(attack_pos);
            }
        }
    }

    // Remove positions that are occupied by pieces from attacked_squares
    for (long long pos : piece_positions) {
        if (attacked_squares.count(pos)) {
            attacked_squares.erase(pos);
        }
    }

    // Total number of available safe positions = total grid size - pieces - attacked squares
    long long total_cells = static_cast<long long>(N) * N;
    long long blocked = piece_positions.size() + attacked_squares.size();

    cout << total_cells - blocked << endl;

    return 0;
}