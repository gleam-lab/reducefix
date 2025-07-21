#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n+1, vector<int>(n+1, 0));

    // Mark positions of all existing pieces
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        grid[x][y] = -1; // -1 to indicate a piece is placed here
    }

    long long safe_squares = 0;

    // Count all empty squares that are not captured by any piece
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (grid[i][j] == 0) { // 0 indicates an empty square
                safe_squares++;
                // Check if it can be captured by a piece
                bool is_captured = false;
                vector<pair<long long, long long>> directions = {
                    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
                };
                for (auto dir : directions) {
                    long long nx = i + dir.first;
                    long long ny = j + dir.second;
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && grid[nx][ny] == -1) {
                        is_captured = true;
                        break;
                    }
                }
                if (!is_captured) {
                    safe_squares++; // Safe square
                }
            }
        }
    }

    cout << safe_squares << endl;
    return 0;
}