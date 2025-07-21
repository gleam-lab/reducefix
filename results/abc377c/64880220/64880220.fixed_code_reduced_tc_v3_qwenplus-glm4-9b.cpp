#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    vector<pair<long long, long long>> pieces;

    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-indexed
        grid[a][b] = true;
        pieces.emplace_back(a, b);
    }

    // Check if a piece can be captured
    auto canBeCaptured = [&](long long x, long long y) {
        const vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny]) {
                return true;
            }
        }
        return false;
    };

    long long count = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (!grid[i][j] && !canBeCaptured(i, j)) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}