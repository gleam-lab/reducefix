#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> map(H, vector<bool>(W, true));
    vector<set<int>> rowWalls(H);
    vector<set<int>> colWalls(W);
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
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
            rowWalls[r].erase(c);
            colWalls[c].erase(r);
        } else {
            // Left
            auto it = rowWalls[r].lower_bound(c);
            if (it != rowWalls[r].begin()) {
                --it;
                int j = *it;
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    rowWalls[r].erase(j);
                    colWalls[j].erase(r);
                }
            }
            // Right
            it = rowWalls[r].upper_bound(c);
            if (it != rowWalls[r].end()) {
                int j = *it;
                if (map[r][j]) {
                    ++broken;
                    map[r][j] = false;
                    rowWalls[r].erase(j);
                    colWalls[j].erase(r);
                }
            }
            // Up
            auto it2 = colWalls[c].lower_bound(r);
            if (it2 != colWalls[c].begin()) {
                --it2;
                int i = *it2;
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    rowWalls[i].erase(c);
                    colWalls[c].erase(i);
                }
            }
            // Down
            it2 = colWalls[c].upper_bound(r);
            if (it2 != colWalls[c].end()) {
                int i = *it2;
                if (map[i][c]) {
                    ++broken;
                    map[i][c] = false;
                    rowWalls[i].erase(c);
                    colWalls[c].erase(i);
                }
            }
        }
    }
    cout << H * W - broken << endl;
    return 0;
}