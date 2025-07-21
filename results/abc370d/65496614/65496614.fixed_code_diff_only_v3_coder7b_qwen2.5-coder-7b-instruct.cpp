#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<set<int>> row(h), col(w);
    
    for(int i = 0; i < h; ++i) row[i].insert(i);
    for(int i = 0; i < w; ++i) col[i].insert(i);
    
    auto erase_wall = [&](int x, int y) {
        if(x < 0 || x >= h || y < 0 || y >= w || !grid[x][y]) return;
        grid[x][y] = false;
        row[x].erase(y);
        col[y].erase(x);
    };
    
    while(q--) {
        int x, y;
        cin >> x >> y;
        --x; --y; // Convert to zero-based index
        
        if(grid[x][y]) {
            erase_wall(x, y);
        } else {
            erase_wall(x - 1, y); // Check above
            erase_wall(x + 1, y); // Check below
            erase_wall(x, y - 1); // Check left
            erase_wall(x, y + 1); // Check right
        }
    }
    
    int count = 0;
    for(int i = 0; i < h; ++i) 
        for(int j = 0; j < w; ++j)
            count += grid[i][j];
            
    cout << count << '\n';
    
    return 0;
}