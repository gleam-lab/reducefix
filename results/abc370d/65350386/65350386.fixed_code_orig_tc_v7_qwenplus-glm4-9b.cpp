#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Wall {
    int row;
    int col;
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<pair<int, int>>> vertical(W); // pair<row, col> indicating a wall at (row, col)
    vector<set<pair<int, int>>> horizontal(H);
    
    // Fill the vertical and horizontal vectors with walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            vertical[j].insert({i, j});
            horizontal[i].insert({i, j});
        }
    }
    
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        auto& vSet = vertical[c];
        auto& hSet = horizontal[r];
        
        if (vSet.count({r, c}) || hSet.count({r, c})) {
            vSet.erase({r, c});
            hSet.erase({r, c});
        } else {
            // Remove the first wall in each direction
            while (!hSet.empty()) {
                auto firstWall = *hSet.begin();
                if (firstWall.first == r && firstWall.second == c) {
                    break;
                }
                hSet.erase(firstWall);
            }
            while (!vSet.empty()) {
                auto firstWall = *vSet.begin();
                if (firstWall.first == r && firstWall.second == c) {
                    break;
                }
                vSet.erase(firstWall);
            }
        }
    }
    
    long long remainingWalls = 0;
    for (auto& v : vertical) {
        remainingWalls += v.size();
    }
    for (auto& h : horizontal) {
        remainingWalls += h.size();
    }
    
    cout << remainingWalls << endl;
    return 0;
}