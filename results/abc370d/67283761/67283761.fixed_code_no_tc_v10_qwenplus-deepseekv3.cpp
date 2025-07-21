#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    
    vector<set<int>> row_walls(H);
    vector<set<int>> col_walls(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int broken = 0;
    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        
        if (map[r][c]) {
            ++broken;
            map[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Check left
            auto it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int j = *it;
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                }
            }
            // Check right
            it = row_walls[r].upper_bound(c);
            if (it != row_walls[r].end()) {
                int j = *it;
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                }
            }
            // Check up
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int i = *it;
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                }
            }
            // Check down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                int i = *it;
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                }
            }
        }
    }
    cout << H * W - broken << endl;

    return 0;
}