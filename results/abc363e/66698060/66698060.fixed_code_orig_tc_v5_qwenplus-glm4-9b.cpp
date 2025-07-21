#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    visited[r][c] = true;
    for (auto& dir : directions) {
        int new_r = r + dir[0], new_c = c + dir[1];
        if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size() && !visited[new_r][new_c] && grid[new_r][new_c] > 0) {
            dfs(new_r, new_c, grid, visited);
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    int initial_area = 0;
    int max_elev = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            max_elev = max(max_elev, grid[i][j]);
            if (grid[i][j] > 0 && visited[i][j] == false) {
                dfs(i, j, grid, visited);
                initial_area++;
            }
        }
    }

    for (int year = 1; year <= y; ++year) {
        int remaining_area = 0;
        bool new_sand = true;
        while (new_sand) {
            new_sand = false;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j) {
                    if (visited[i][j] == false) {
                        bool can_sink = false;
                        for (auto& dir : directions) {
                            int new_r = i + dir[0], new_c = j + dir[1];
                            if (new_r >= 0 && new_r < h && new_c >= 0 && new_c < w) {
                                if (visited[new_r][new_c] == true) {
                                    can_sink = true;
                                    break;
                                }
                            }
                        }
                        if (can_sink) {
                            visited[i][j] = true;
                            new_sand = true;
                        }
                    }
                }
            }
        }
        cout << initial_area - (initial_area - remaining_area) << endl;
    }

    return 0;
}