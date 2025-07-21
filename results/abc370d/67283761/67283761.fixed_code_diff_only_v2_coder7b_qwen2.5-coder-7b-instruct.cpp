#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    
    // Directions: Left, Right, Up, Down
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int broken = 0;

    for(int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Adjusting for zero-based indexing
        
        if (map[r][c]) {
            ++broken;
            map[r][c] = false;
        } else {
            for (auto& [dr, dc] : directions) {
                int x = r, y = c;
                while(true) {
                    x += dr;
                    y += dc;
                    
                    // Check bounds
                    if (x < 0 || x >= H || y < 0 || y >= W) break;
                    
                    // If we hit a wall, destroy it and update direction count
                    if (map[x][y]) {
                        ++broken;
                        map[x][y] = false;
                        break;
                    }
                }
            }
        }
    }

    cout << (H * W - broken) << endl;
    return 0;
}