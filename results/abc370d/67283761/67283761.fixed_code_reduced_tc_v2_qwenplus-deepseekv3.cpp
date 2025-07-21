#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rowWalls(H + 1); // 1-based indexing for rows
    vector<set<int>> colWalls(W + 1); // 1-based indexing for columns
    
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rowWalls[i].insert(j);
            colWalls[j].insert(i);
        }
    }
    
    int broken = 0;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        
        if (rowWalls[r].count(c)) {
            // Wall exists, destroy it
            rowWalls[r].erase(c);
            colWalls[c].erase(r);
            broken++;
        } else {
            // No wall, find first walls in four directions
            // Left
            auto it = rowWalls[r].lower_bound(c);
            if (it != rowWalls[r].begin()) {
                --it;
                int j = *it;
                rowWalls[r].erase(j);
                colWalls[j].erase(r);
                broken++;
            }
            // Right
            it = rowWalls[r].lower_bound(c);
            if (it != rowWalls[r].end()) {
                int j = *it;
                rowWalls[r].erase(j);
                colWalls[j].erase(r);
                broken++;
            }
            // Up
            it = colWalls[c].lower_bound(r);
            if (it != colWalls[c].begin()) {
                --it;
                int i = *it;
                rowWalls[i].erase(c);
                colWalls[c].erase(i);
                broken++;
            }
            // Down
            it = colWalls[c].lower_bound(r);
            if (it != colWalls[c].end()) {
                int i = *it;
                rowWalls[i].erase(c);
                colWalls[c].erase(i);
                broken++;
            }
        }
    }
    
    cout << H * W - broken << '\n';
    
    return 0;
}