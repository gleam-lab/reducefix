#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<set<int>> rowWalls(H), colWalls(W);
    ll totalWalls = H * W;
    ll remainingWalls = H * W;
    
    // Each cell starts with W-1 walls (excluding itself)
    ll initialWalls = (W - 1) * (H - 1);
    remainingWalls -= initialWalls;
    
    // Process each query
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based index
        
        // If there's a wall at (R, C), destroy it
        if (rowWalls[R].find(C) != rowWalls[R].end()) {
            rowWalls[R].erase(C);
            colWalls[C].erase(R);
            --remainingWalls;
        } else {
            // No wall at (R, C), destroy walls around it
            // Check and remove walls above and below
            for (int i = R - 1; i >= 0 && rowWalls[i].find(C) != rowWalls[i].end(); --i) {
                rowWalls[i].erase(C);
                colWalls[C].erase(i);
                --remainingWalls;
            }
            for (int i = R + 1; i < H && rowWalls[i].find(C) != rowWalls[i].end(); ++i) {
                rowWalls[i].erase(C);
                colWalls[C].erase(i);
                --remainingWalls;
            }
            // Check and remove walls to the left and right
            for (int j = C - 1; j >= 0 && colWalls[j].find(R) != colWalls[j].end(); --j) {
                colWalls[j].erase(R);
                rowWalls[R].erase(j);
                --remainingWalls;
            }
            for (int j = C + 1; j < W && colWalls[j].find(R) != colWalls[j].end(); ++j) {
                colWalls[j].erase(R);
                rowWalls[R].erase(j);
                --remainingWalls;
            }
        }
    }
    
    cout << remainingWalls << endl;
    return 0;
}