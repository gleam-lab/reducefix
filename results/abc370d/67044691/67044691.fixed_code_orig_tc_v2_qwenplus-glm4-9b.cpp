#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Wall {
    int r, c, d; // d = 1 for up, -1 for down, 2 for left, -2 for right
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<set<int>>> up(H + 1, vector<set<int>>(W + 1));
    vector<vector<set<int>>> down(H + 1, vector<set<int>>(W + 1));
    vector<vector<set<int>>> left(H + 1, vector<set<int>>(W + 1));
    vector<vector<set<int>>> right(H + 1, vector<set<int>>(W + 1));
    
    // Initialize all cells with walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            up[i][j].insert(j);
            down[i][j].insert(j);
            left[i][j].insert(i);
            right[i][j].insert(i);
        }
    }
    
    int ans = H * W; // Initial count of walls
    vector<Wall> walls;
    vector<pair<int, int>> queries(Q);
    
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        queries[i] = {r, c};
    }
    
    // Process each query
    for (auto &q : queries) {
        int r = q.first, c = q.second;
        
        // Check if the wall exists at (r, c)
        if (up[r][c].find(c) != up[r][c].end()) {
            up[r][c].erase(c);
            down[r][c].erase(c);
            left[r][c].erase(c);
            right[r][c].erase(c);
            ans--; // One wall is destroyed
        } else {
            // No wall at (r, c), destroy walls in all four directions
            if (c > 1) {
                if (right[r][c].find(c - 1) != right[r][c].end()) {
                    right[r][c].erase(c - 1);
                    left[r][c].erase(c - 1);
                }
            }
            if (c < W) {
                if (left[r][c].find(c + 1) != left[r][c].end()) {
                    left[r][c].erase(c + 1);
                    right[r][c].erase(c + 1);
                }
            }
            if (r > 1) {
                if (up[r][c].find(c) != up[r][c].end()) {
                    up[r][c].erase(c);
                    down[r][c].erase(c);
                }
            }
            if (r < H) {
                if (down[r][c].find(c) != down[r][c].end()) {
                    down[r][c].erase(c);
                    up[r][c].erase(c);
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}