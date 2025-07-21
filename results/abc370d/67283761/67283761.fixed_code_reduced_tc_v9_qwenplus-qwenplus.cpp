#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <utility>

using namespace std;

// Directions: Up, Down, Left, Right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    // For each cell and direction, keep track of the next wall in that direction
    vector<vector<vector<int>>> next_wall(4, vector<vector<int>>(H, vector<int>(W, -1)));

    // Using BFS to precompute next walls in all directions
    // We'll do a BFS from every edge (top, bottom, left, right) for respective directions
    queue<pair<int, int>> q;

    // Initialize for Up direction (from top to bottom)
    for (int j = 0; j < W; ++j) {
        for (int i = 0; i < H; ++i) {
            if (i == 0) {
                if (has_wall[i][j]) {
                    q.emplace(i, j);
                    next_wall[0][i][j] = i;
                }
            } else {
                if (has_wall[i][j]) {
                    next_wall[0][i][j] = next_wall[0][i-1][j];
                }
            }
        }
    }

    // Initialize for Down direction (from bottom to top)
    for (int j = 0; j < W; ++j) {
        for (int i = H-1; i >= 0; --i) {
            if (i == H-1) {
                if (has_wall[i][j]) {
                    q.emplace(i, j);
                    next_wall[1][i][j] = i;
                }
            } else {
                if (has_wall[i][j]) {
                    next_wall[1][i][j] = next_wall[1][i+1][j];
                }
            }
        }
    }

    // Initialize for Left direction (from left to right)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (j == 0) {
                if (has_wall[i][j]) {
                    q.emplace(i, j);
                    next_wall[2][i][j] = j;
                }
            } else {
                if (has_wall[i][j]) {
                    next_wall[2][i][j] = next_wall[2][i][j-1];
                }
            }
        }
    }

    // Initialize for Right direction (from right to left)
    for (int i = 0; i < H; ++i) {
        for (int j = W-1; j >= 0; --j) {
            if (j == W-1) {
                if (has_wall[i][j]) {
                    q.emplace(i, j);
                    next_wall[3][i][j] = j;
                }
            } else {
                if (has_wall[i][j]) {
                    next_wall[3][i][j] = next_wall[3][i][j+1];
                }
            }
        }
    }

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < H && y >= 0 && y < W;
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (has_wall[r][c]) {
            // Directly bomb this cell
            has_wall[r][c] = false;

            // Update in all directions
            for (int d = 0; d < 4; ++d) {
                int x = r + dx[d], y = c + dy[d];
                if (is_valid(x, y) && !has_wall[x][y]) {
                    // This cell might need to update its pointers
                    q.emplace(x, y);
                }
            }
        } else {
            // Bomb explodes in four directions
            vector<pair<int, int>> to_break;

            for (int d = 0; d < 4; ++d) {
                int nx = r, ny = c;
                while (true) {
                    nx += dx[d];
                    ny += dy[d];
                    if (!is_valid(nx, ny)) break;
                    if (has_wall[nx][ny]) {
                        to_break.emplace_back(nx, ny);
                        break;
                    }
                }
            }

            for (auto [x, y] : to_break) {
                has_wall[x][y] = false;
                // Add to queue to update pointers
                q.emplace(x, y);
            }
        }

        // Process updates due to destroyed walls using BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (!is_valid(nx, ny)) continue;

                // Check if we need to update the pointer
                bool changed = false;
                if (dx[d] == -1) { // Up
                    if (x > 0 && next_wall[0][x][y] == -1 && has_wall[x][y]) {
                        next_wall[0][x][y] = next_wall[0][x+1][y];
                        changed = true;
                    }
                } else if (dx[d] == 1) { // Down
                    if (x < H-1 && next_wall[1][x][y] == -1 && has_wall[x][y]) {
                        next_wall[1][x][y] = next_wall[1][x-1][y];
                        changed = true;
                    }
                } else if (dy[d] == -1) { // Left
                    if (y > 0 && next_wall[2][x][y] == -1 && has_wall[x][y]) {
                        next_wall[2][x][y] = next_wall[2][x][y+1];
                        changed = true;
                    }
                } else if (dy[d] == 1) { // Right
                    if (y < W-1 && next_wall[3][x][y] == -1 && has_wall[x][y]) {
                        next_wall[3][x][y] = next_wall[3][x][y-1];
                        changed = true;
                    }
                }

                if (changed) {
                    q.emplace(nx, ny);
                }
            }
        }
    }

    // Count remaining walls
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}