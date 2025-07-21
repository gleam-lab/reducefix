#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<map<int, int>> rows(h);
    vector<map<int, int>> cols(w);
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (!rows[r].contains(c)) {
            rows[r][c] = rows.size();
            cols[c][r] = cols.size();
        } else {
            int idx = rows[r][c];
            int prev_min = idx;
            
            // Remove current index from both maps
            rows[r].erase(c);
            cols[c].erase(r);
            
            // Merge with previous indices
            while (prev_min > 0 && rows[r].contains(prev_min - 1)) {
                int prev_idx = rows[r][prev_min - 1];
                rows[r].erase(prev_min - 1);
                cols[prev_min - 1].erase(r);
                
                prev_min = prev_idx;
            }
            
            while (cols[c].contains(prev_min - 1)) {
                int prev_idx = cols[c][prev_min - 1];
                cols[c].erase(prev_min - 1);
                rows[prev_min - 1].erase(c);
                
                prev_min = prev_idx;
            }
            
            rows[r][c] = prev_min;
            cols[c][r] = prev_min;
        }
    }

    int total_walls = h * w;
    for (const auto& row : rows) {
        total_walls -= row.size();
    }
    for (const auto& col : cols) {
        total_walls -= col.size();
    }
    cout << total_walls << endl;
    
    return 0;
}