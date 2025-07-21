#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0}; // Up, Down, Left, Right
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));

    // For each direction and cell, maintain the next wall position
    vector<vector<int>> left(W + 2, vector<int>(H, -1));
    vector<vector<int>> right(W + 2, vector<int>(H, -1));
    vector<vector<int>> up(H + 2, vector<int>(W, -1));
    vector<vector<int>> down(H + 2, vector<int>(W, -1));

    auto get_next = [&](int x, int y, int dir) -> int {
        if (dir == 0) return up[x][y];   // Up
        if (dir == 1) return down[x][y]; // Down
        if (dir == 2) return left[y][x]; // Left
        return right[y][x];              // Right
    };

    for (int i = 0; i < H; ++i) {
        // Initialize left and right pointers
        int last_wall = -1;
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) {
                left[j][i] = last_wall;
                last_wall = j;
            } else {
                left[j][i] = -2;
            }
        }

        last_wall = -1;
        for (int j = W-1; j >= 0; --j) {
            if (has_wall[i][j]) {
                right[j][i] = last_wall;
                last_wall = j;
            } else {
                right[j][i] = -2;
            }
        }
    }

    for (int j = 0; j < W; ++j) {
        // Initialize up and down pointers
        int last_wall = -1;
        for (int i = 0; i < H; ++i) {
            if (has_wall[i][j]) {
                up[i][j] = last_wall;
                last_wall = i;
            } else {
                up[i][j] = -2;
            }
        }

        last_wall = -1;
        for (int i = H-1; i >= 0; --i) {
            if (has_wall[i][j]) {
                down[i][j] = last_wall;
                last_wall = i;
            } else {
                down[i][j] = -2;
            }
        }
    }

    int remaining = H * W;

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (has_wall[r][c]) {
            // Bomb hits a wall directly
            has_wall[r][c] = false;
            remaining--;
            
            // Update neighbor pointers
            if (up[r][c] != -2) down[up[r][c]][c] = down[r][c];
            if (down[r][c] != -2) up[down[r][c]][c] = up[r][c];
            
            if (left[c][r] != -2) right[left[c][r]][r] = right[r][c];
            if (right[c][r] != -2) left[right[c][r]][r] = left[c][r];
        } else {
            // Bomb triggers explosion in four directions
            for (int d = 0; d < 4; ++d) {
                int nx = r + dx[d], ny = c + dy[d];
                while (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if (has_wall[nx][ny]) {
                        has_wall[nx][ny] = false;
                        remaining--;
                        
                        // Update neighbor pointers
                        if (up[nx][ny] != -2) down[up[nx][ny]][ny] = down[nx][ny];
                        if (down[nx][ny] != -2) up[down[nx][ny]][ny] = up[nx][ny];
                        
                        if (left[ny][nx] != -2) right[left[ny][nx]][nx] = right[nx][ny];
                        if (right[ny][nx] != -2) left[right[ny][nx]][nx] = left[ny][nx];
                        
                        break;
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }
    }

    cout << remaining << "\n";
    return 0;
}