#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    long long threat_count = 0;

    // Directions for capturing pieces
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;  // Convert to 0-based index

        // For each piece, mark the cells it can capture
        for (const auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            // Ensure the coordinates are within bounds
            if (x >= 0 && x < n && y >= 0 && y < n) {
                grid[x][y] = 1; // Mark as threatened
                threat_count++;
            }
        }
    }

    // Calculate the number of empty cells not under threat
    long long result = n * n - threat_count;
    cout << result << endl;

    return 0;
}