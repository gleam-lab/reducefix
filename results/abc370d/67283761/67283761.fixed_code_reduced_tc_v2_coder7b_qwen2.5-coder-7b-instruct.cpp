#include <vector>
#include <deque>
#include <queue>
#include <tuple>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <climits>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;
#pragma warning(disable: 4189)
#pragma warning(disable: 4267)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    
    deque<array<int, 3>> queue;
    
    while(Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            grid[r][c] = false;
            queue.push_back({r, c, 0});
        } else {
            for(int d = 0; d < 4; ++d) {
                int dr[4] = {-1, 1, 0, 0};
                int dc[4] = {0, 0, -1, 1};
                
                int x = r + dr[d];
                int y = c + dc[d];
                
                while(x >= 0 && x < H && y >= 0 && y < W && !grid[x][y]) {
                    x += dr[d];
                    y += dc[d];
                }
                
                if(x >= 0 && x < H && y >= 0 && y < W) {
                    grid[x][y] = false;
                    queue.push_back({x, y, d});
                }
            }
        }
    }

    int count = 0;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(grid[i][j]) count++;
        }
    }

    cout << count << endl;
    
    return 0;
}