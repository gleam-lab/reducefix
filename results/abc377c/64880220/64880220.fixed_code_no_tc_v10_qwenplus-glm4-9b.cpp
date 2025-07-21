#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    
    // Read positions of existing pieces and mark them in the grid
    for (int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        grid[a][b] = 1;
    }
    
    // Check if a piece can be placed at (i, j)
    // without being captured by existing pieces
    auto can_place = [&](long long i, long long j) {
        vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
        for (int k = 0; k < 8; k++) {
            long long x = i + dx[k];
            long long y = j + dy[k];
            if (x > 0 && x <= n && y > 0 && y <= n && grid[x][y]) {
                return false;
            }
        }
        return true;
    };
    
    long long ans = 0;
    // Count all empty squares that can be occupied
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            if (grid[i][j] == 0 && can_place(i, j)) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}