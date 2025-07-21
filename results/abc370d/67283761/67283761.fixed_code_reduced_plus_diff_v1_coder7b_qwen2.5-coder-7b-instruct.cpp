#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

struct Bomb {
    int r, c, t;
};

bool operator<(const Bomb& b1, const Bomb& b2) {
    return b1.t > b2.t;
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    
    priority_queue<Bomb> bombs;
    
    for(int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        bombs.emplace(r, c, q);
    }
    
    while(!bombs.empty()) {
        auto [r, c, t] = bombs.top();
        bombs.pop();
        
        if (!grid[r][c]) continue;
        
        grid[r][c] = false;
        
        // Check up
        for(int i = r-1; i >= 0; --i) {
            if(grid[i][c]) break;
            grid[i][c] = false;
        }
        
        // Check down
        for(int i = r+1; i < H; ++i) {
            if(grid[i][c]) break;
            grid[i][c] = false;
        }
        
        // Check left
        for(int j = c-1; j >= 0; --j) {
            if(grid[r][j]) break;
            grid[r][j] = false;
        }
        
        // Check right
        for(int j = c+1; j < W; ++j) {
            if(grid[r][j]) break;
            grid[r][j] = false;
        }
    }
    
    int count = 0;
    for(const auto& row : grid) {
        for(bool cell : row) {
            if(cell) ++count;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}