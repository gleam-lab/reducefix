#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    // Directions for capturing pieces
    vector<vector<long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to keep track of invalid positions
    vector<vector<bool>> invalid(N, vector<bool>(N, false));

    // Mark invalid positions based on the given pieces
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert to zero-based index

        for (auto& dir : directions) {
            long long new_a = a + dir[0];
            long long new_b = b + dir[1];

            // Check boundaries
            if (new_a >= 0 && new_a < N && new_b >= 0 && new_b < N) {
                invalid[new_a][new_b] = true;
            }
        }
    }

    // Calculate the number of valid positions
    long long valid_positions = 0;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            if (!invalid[i][j]) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}