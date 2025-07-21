#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> tate(W), yoko(H);
    
    // Populate the sets with the initial walls
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    }
    
    for (int query = 0; query < Q; query++) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to zero-based index
        
        // Check if there's a wall at the specified position
        if (tate[C].find(R) != tate[C].end()) {
            tate[C].erase(R);
            yoko[R].erase(C);
        } else {
            // If no wall at (R, C), we need to remove walls in all four directions
            int r = R - 1;
            while (r >= 0 && yoko[r].find(C) != yoko[r].end()) {
                tate[C].erase(r);
                yoko[r].erase(C);
                --r;
            }
            
            r = R + 1;
            while (r < H && yoko[r].find(C) != yoko[r].end()) {
                tate[C].erase(r);
                yoko[r].erase(C);
                ++r;
            }
            
            int c = C - 1;
            while (c >= 0 && tate[c].find(R) != tate[c].end()) {
                yoko[R].erase(c);
                tate[c].erase(R);
                --c;
            }
            
            c = C + 1;
            while (c < W && tate[c].find(R) != tate[c].end()) {
                yoko[R].erase(c);
                tate[c].erase(R);
                ++c;
            }
        }
    }
    
    int remainingWalls = 0;
    // Count the remaining number of walls
    for (int i = 0; i < W; i++) {
        remainingWalls += tate[i].size();
    }
    
    cout << remainingWalls << endl;
    return 0;
}