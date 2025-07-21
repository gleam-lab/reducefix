#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
int H, W, Q;
bool wall[4][MAXN]; // directions: 0=left, 1=right, 2=up, 3=down

// Convert (r,c) to linear index
int idx(int r, int c) {
    return r * W + c;
}

// For each cell, find the first wall in each direction when starting from it
void init_directions(vector<vector<bool>> &grid) {
    // Left and Right
    for (int r = 0; r < H; ++r) {
        int last_wall = -1;
        for (int c = 0; c < W; ++c) {
            if (grid[r][c]) {
                if (last_wall != -1) {
                    wall[0][idx(r, c)] = false;
                    wall[1][idx(r, last_wall)] = false;
                }
                last_wall = idx(r, c);
            } else {
                wall[0][idx(r, c)] = true;
            }
        }
        last_wall = -1;
        for (int c = W-1; c >= 0; --c) {
            if (grid[r][c]) {
                if (last_wall != -1) {
                    wall[1][idx(r, c)] = false;
                }
                last_wall = idx(r, c);
            } else {
                wall[1][idx(r, c)] = true;
            }
        }
    }

    // Up and Down
    for (int c = 0; c < W; ++c) {
        int last_wall = -1;
        for (int r = 0; r < H; ++r) {
            if (grid[r][c]) {
                if (last_wall != -1) {
                    wall[2][idx(r, c)] = false;
                    wall[3][idx(last_wall, c)] = false;
                }
                last_wall = idx(r, c);
            } else {
                wall[2][idx(r, c)] = true;
            }
        }
        last_wall = -1;
        for (int r = H-1; r >= 0; --r) {
            if (grid[r][c]) {
                if (last_wall != -1) {
                    wall[3][idx(r, c)] = true;
                }
                last_wall = idx(r, c);
            } else {
                wall[3][idx(r, c)] = true;
            }
        }
    }
}

// Update walls in a specific direction after destroying one
void destroy(int pos, vector<vector<bool>> &grid) {
    // Mark as no wall anymore
    grid[pos / W][pos % W] = false;

    // Update adjacent directions
    for (int d = 0; d < 4; ++d) {
        if (wall[d][pos] == false) continue;

        // Find next wall in this direction
        int nr = pos / W, nc = pos % W;
        if (d == 0) nc--;
        else if (d == 1) nc++;
        else if (d == 2) nr--;
        else if (d == 3) nr++;

        while (nr >= 0 && nr < H && nc >= 0 && nc < W && !grid[nr][nc]) {
            nr += (d == 0 ? 0 : (d == 1 ? 0 : (d == 2 ? -1 : 1));
            nc += (d == 0 ? -1 : (d == 1 ? 1 : 0));
        }

        if (nr >= 0 && nr < H && nc >= 0 && nc < W)
            wall[d][pos] = false;
        else
            wall[d][pos] = true;
    }
}

int main() {
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));

    // Initialize direction pointers
    memset(wall, false, sizeof(wall));
    init_directions(grid);

    int remaining = H * W;

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        int pos = idx(r, c);

        if (grid[r][c]) {
            remaining--;
            grid[r][c] = false;
            destroy(pos, grid);
        } else {
            // Destroy up, down, left, right
            int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int d = 0; d < 4; ++d) {
                int dr = dirs[d][0], dc = dirs[d][1];
                int cr = r + dr, cc = c + dc;

                while (cr >= 0 && cr < H && cc >= 0 && cc < W) {
                    if (grid[cr][cc]) {
                        grid[cr][cc] = false;
                        remaining--;
                        destroy(idx(cr, cc), grid);
                        break;
                    }
                    cr += dr;
                    cc += dc;
                }
            }
        }
    }

    cout << remaining << endl;
}