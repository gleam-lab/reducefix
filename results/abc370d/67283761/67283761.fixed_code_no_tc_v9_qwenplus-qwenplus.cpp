#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    int total_walls = H * W;

    // For each cell and direction, we maintain the next reachable cell
    // Directions: 0=up, 1=down, 2=left, 3=right
    vector<vector<array<int, 4>>> next_cell(H, vector<array<int, 4>>(W));

    // Initialize directions
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            next_cell[i][j] = {i - 1, i + 1, j - 1, j + 1}; // up, down, left, right
        }
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    };

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (has_wall[r][c]) {
            has_wall[r][c] = false;
            total_walls--;
            
            // Update neighbors' pointers
            if (valid(next_cell[r][c][0], c)) next_cell[next_cell[r][c][0]][c][1] = next_cell[r][c][1];
            if (valid(next_cell[r][c][1], c)) next_cell[next_cell[r][c][1]][c][0] = next_cell[r][c][0];
            if (valid(r, next_cell[r][c][2])) next_cell[r][next_cell[r][c][2]][3] = next_cell[r][c][3];
            if (valid(r, next_cell[r][c][3])) next_cell[r][next_cell[r][c][3]][2] = next_cell[r][c][2];
        } else {
            // Bomb already here, now detonate in four directions
            for (int dir = 0; dir < 4; ++dir) {
                int nr = r, nc = c;
                while (true) {
                    if (dir == 0) nr = next_cell[nr][nc][0]; // up
                    else if (dir == 1) nr = next_cell[nr][nc][1]; // down
                    else if (dir == 2) nc = next_cell[nr][nc][2]; // left
                    else if (dir == 3) nc = next_cell[nr][nc][3]; // right
                    
                    if (!valid(nr, nc)) break;
                    
                    if (has_wall[nr][nc]) {
                        has_wall[nr][nc] = false;
                        total_walls--;

                        // Update neighbors' pointers for the destroyed wall
                        if (valid(next_cell[nr][nc][0], nc)) next_cell[next_cell[nr][nc][0]][nc][1] = next_cell[nr][nc][1];
                        if (valid(next_cell[nr][nc][1], nc)) next_cell[next_cell[nr][nc][1]][nc][0] = next_cell[nr][nc][0];
                        if (valid(nr, next_cell[nr][nc][2])) next_cell[nr][next_cell[nr][nc][2]][3] = next_cell[nr][nc][3];
                        if (valid(nr, next_cell[nr][nc][3])) next_cell[nr][next_cell[nr][nc][3]][2] = next_cell[nr][nc][2];
                        
                        break;
                    }
                }
            }
        }
    }

    cout << total_walls << endl;
    return 0;
}