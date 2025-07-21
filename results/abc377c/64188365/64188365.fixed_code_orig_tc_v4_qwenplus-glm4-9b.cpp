#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000000; // Maximum size of the grid

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> safe(n, vector<int>(n, 1)); // Initialize a safe grid
    
    // Loop over each piece
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index
        
        // Check all possible cells that this piece can capture
        int directions[][2] = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto& dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                safe[nr][nc] = 0; // Mark the captured cell as unsafe
            }
        }
    }
    
    // Calculate the number of safe cells
    long long safe_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            safe_count += safe[i][j];
        }
    }
    
    cout << safe_count << endl;
    return 0;
}