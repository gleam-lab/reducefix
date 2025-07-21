#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

void solve(const vector<pair<int, int>>& pieces, int n) {
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

    // Update the grid with the number of pieces that can attack each cell
    for (auto& piece : pieces) {
        int x = piece.first;
        int y = piece.second;

        // Directions of attack
        int directions[][4] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                grid[nx][ny]++;
            }
        }
    }

    // Calculate the number of attackable cells using prefix sums
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            grid[i][j] = (grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1] + MOD) % MOD;
        }
    }

    // Calculate the number of attackable cells
    long long attackable_cells = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            attackable_cells = (attackable_cells + grid[i][j]) % MOD;
        }
    }

    // The number of non-attackable cells is the total cells minus the number of attackable cells
    long long non_attackable_cells = long long(n) * n - attackable_cells;
    cout << non_attackable_cells << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    solve(pieces, n);
    return 0;
}