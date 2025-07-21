#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> captured_cells;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Directions in which the piece can capture other pieces
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& dir : directions) {
            int new_a = a + dir.first;
            int new_b = b + dir.second;

            // Check if the new cell is within the grid bounds
            if (1 <= new_a && new_a <= N && 1 <= new_b && new_b <= N) {
                captured_cells.insert({new_a, new_b});
            }
        }
    }

    // Total cells minus the number of captured cells
    cout << N * N - captured_cells.size() << endl;

    return 0;
}