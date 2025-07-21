#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_H = 50000;
const int MAX_W = 50000;
const int WALL = 1;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<int> row_walls(MAX_H, (1 << MAX_W) - 1); // bitmask for each row
    vector<int> col_walls(MAX_W, (1 << MAX_H) - 1); // bitmask for each column
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based index
        
        int& r_walls = row_walls[R];
        int& c_walls = col_walls[C];
        
        if ((r_walls & (1 << C)) == 0) { // No wall at (R, C)
            // Destroy walls in the column
            for (int i = 0; i < H; ++i) {
                if ((r_walls & (1 << i)) == 0) { // No wall at (i, C)
                    c_walls &= ~(1 << i); // Remove wall at (i, C)
                }
            }
            
            // Destroy walls in the row
            for (int j = 0; j < W; ++j) {
                if ((c_walls & (1 << j)) == 0) { // No wall at (R, j)
                    r_walls &= ~(1 << j); // Remove wall at (R, j)
                }
            }
        } else {
            // Remove the wall at (R, C)
            r_walls &= ~(1 << C);
            c_walls &= ~(1 << C);
        }
    }
    
    int remaining_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((row_walls[i] & (1 << j)) == 0 && (col_walls[j] & (1 << i)) == 0) {
                remaining_walls++;
            }
        }
    }
    
    cout << remaining_walls << endl;
    
    return 0;
}