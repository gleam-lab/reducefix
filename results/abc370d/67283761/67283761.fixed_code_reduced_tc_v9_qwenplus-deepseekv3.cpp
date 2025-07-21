#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H + 2, vector<bool>(W + 2, false));
    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            grid[i][j] = true;
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }
    
    int broken = 0;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (grid[r][c]) {
            grid[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            broken++;
        } else {
            // Check up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                if (grid[i][c]) {
                    grid[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    broken++;
                }
            }
            // Check down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                if (grid[i][c]) {
                    grid[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                    broken++;
                }
            }
            // Check left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                if (grid[r][j]) {
                    grid[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                    broken++;
                }
            }
            // Check right
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                if (grid[r][j]) {
                    grid[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                    broken++;
                }
            }
        }
    }
    
    cout << H * W - broken << '\n';
    
    return 0;
}