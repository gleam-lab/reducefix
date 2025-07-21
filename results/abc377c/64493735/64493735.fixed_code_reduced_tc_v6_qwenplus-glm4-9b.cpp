#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll n, m;
vector<vector<int>> grid;

ll flatIndex(int row, int col) {
    return row * n + col;
}

void placePiece(int a, int b) {
    // Mark the current cell
    grid[a][b] = 1;
    
    // Mark all cells that can be captured
    grid[a+1][b+2] = grid[a+2][b+1] = grid[a+2][b-1] = grid[a+1][b-2] = grid[a-1][b+2] = grid[a-2][b+1] = grid[a-2][b-1] = grid[a-1][b-2] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        placePiece(a - 1, b - 1); // Convert 1-based to 0-based
    }

    ll emptyCount = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (grid[row][col] == 0) {
                emptyCount++;
            }
        }
    }

    cout << emptyCount << endl;

    return 0;
}