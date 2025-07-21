#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Directions in which a piece can capture another piece
    vector<array<long long, 2>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to store the positions of the pieces
    set<array<long long, 2>> pieces;

    // Read the positions of the pieces
    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        --x, --y; // Convert 1-based index to 0-based index
        pieces.insert({x, y});
    }

    // Count the number of valid positions
    long long valid_positions = 0;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            bool is_valid = true;
            for (auto& dir : directions) {
                long long nx = i + dir[0];
                long long ny = j + dir[1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (pieces.count({nx, ny})) {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (is_valid) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}