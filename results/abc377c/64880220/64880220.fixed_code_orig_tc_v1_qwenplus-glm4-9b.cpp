#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000; // Adjusted according to the problem constraints

int main() {
    long long N, M;
    cin >> N >> M;

    vector<vector<bool>> grid(N, vector<bool>(N, true)); // All cells are initially empty (true)

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-indexed

        // Directions in which the piece can capture
        int directions[8][2] = {
            {1, 2}, {2, 1}, {2, -1}, {1, -2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };

        for (int j = 0; j < 8; ++j) {
            int x = a + directions[j][0];
            int y = b + directions[j][1];
            
            // Check if the resulting position is within grid bounds
            if (x >= 0 && x < N && y >= 0 && y < N) {
                // Mark the cell as captured
                grid[x][y] = false;
            }
        }
    }

    // Count the number of cells that are still empty
    long long count_empty = 0;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if (grid[i][j]) count_empty++;
        }
    }

    cout << count_empty << endl;

    return 0;
}