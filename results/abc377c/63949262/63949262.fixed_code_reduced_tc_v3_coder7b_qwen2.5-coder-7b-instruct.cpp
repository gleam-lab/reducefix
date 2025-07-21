#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input values
    int N;
    int M;
    cin >> N >> M;

    // Set to store unique positions that can be attacked
    set<pair<int, int>> attacking_positions;

    // Process each piece
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        // Check all possible moves
        vector<pair<int, int>> moves = {
            {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2},
            {x - 2, y + 1}, {x - 2, y - 1}, {x - 1, y - 2},
            {x + 1, y - 2}, {x + 2, y - 1}
        };

        for (const auto& move : moves) {
            int nx = move.first;
            int ny = move.second;

            // Check if the new position is within bounds
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacking_positions.insert({nx, ny});
            }
        }
    }

    // Calculate the number of safe positions
    long long total_positions = static_cast<long long>(N) * N;
    long long safe_positions = total_positions - attacking_positions.size();

    // Output the result
    cout << safe_positions << endl;

    return 0;
}