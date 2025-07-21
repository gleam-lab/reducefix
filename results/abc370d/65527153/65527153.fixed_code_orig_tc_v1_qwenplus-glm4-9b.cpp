#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 400010; // Slightly larger than maximum required to handle edge cases

vector<vector<set<int>>> grid(MAX_N, vector<set<int>>(MAX_N, {0, 0, 0, 0}));

void destroy_walls(int r, int c) {
    // Check and destroy wall at (r, c)
    grid[r][c].clear();

    // Destroy walls upwards
    for (int i = r - 1; i > 0; --i) {
        if (grid[i][c].count(1)) {
            grid[i][c].erase(1);
        } else {
            break;
        }
    }

    // Destroy walls downwards
    for (int i = r + 1; i < grid.size() - 1; ++i) {
        if (grid[i][c].count(2)) {
            grid[i][c].erase(2);
        } else {
            break;
        }
    }

    // Destroy walls to the left
    for (int j = c - 1; j > 0; --j) {
        if (grid[r][j].count(3)) {
            grid[r][j].erase(3);
        } else {
            break;
        }
    }

    // Destroy walls to the right
    for (int j = c + 1; j < grid[r].size() - 1; ++j) {
        if (grid[r][j].count(4)) {
            grid[r][j].erase(4);
        } else {
            break;
        }
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Input queries
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index
        if (grid[r][c].size() > 0) {
            destroy_walls(r, c);
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += grid[i][j].size();
        }
    }

    cout << remaining_walls << endl;
    return 0;
}