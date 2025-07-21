#include <bits/stdc++.h>
using namespace std;

// Function to perform binary search to find the lower bound
int lowerBound(vector<int>& arr, int target) {
    int l = 0, r = arr.size();
    while(l < r) {
        int m = l + (r - l) / 2;
        if(arr[m] >= target) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<int>> grid(h, vector<int>(w, 1));
    set<int> rows[h], cols[w];
    
    for(int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            grid[r][c] = 0;
            rows[r].erase(rows[r].find(c));
            cols[c].erase(cols[c].find(r));
        } else {
            int lb_r = lowerBound(rows[r], c), lb_c = lowerBound(cols[c], r);
            
            if(lb_r != rows[r].size()) {
                int col = *(rows[r].begin() + lb_r);
                if(col == c) continue;
                grid[r][col] = 0;
                rows[r].erase(rows[r].find(col));
                cols[col].erase(cols[col].find(r));
            }
            
            if(lb_c != cols[c].size()) {
                int row = *(cols[c].begin() + lb_c);
                if(row == r) continue;
                grid[row][c] = 0;
                rows[row].erase(rows[row].find(c));
                cols[c].erase(cols[c].find(row));
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < h; ++i) 
        for(int j = 0; j < w; ++j)
            if(grid[i][j]) ++ans;
    
    cout << ans << '\n';
    
    return 0;
}