#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input
    int N;
    cin >> N;
    int M;
    cin >> M;

    // Set to store positions of existing knights
    set<pair<int, int>> knight_positions;

    // Read positions of existing knights
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        knight_positions.insert({x, y});
    }

    // Directions for knight moves
    vector<pair<int, int>> knight_moves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    // Set to store positions that can be captured by any knight
    set<pair<int, int>> capture_positions;

    // Mark all positions that can be captured by any knight
    for (const auto& pos : knight_positions) {
        int x = pos.first;
        int y = pos.second;
        for (const auto& move : knight_moves) {
            int nx = x + move.first;
            int ny = y + move.second;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                capture_positions.insert({nx, ny});
            }
        }
    }

    // Calculate the number of empty squares
    int empty_squares = N * N - capture_positions.size();

    // Output the result
    cout << empty_squares << endl;

    return 0;
}