#include <iostream>
#include <vector>

using namespace std;

const int MAX_H = 400005;
const int MAX_W = 400005;

vector<vector<bool>> grid(MAX_H + 2, vector<bool>(MAX_W + 2, true));
vector<vector<int>> rows(MAX_H + 2, vector<int>(MAX_W + 2, -1)); // -1 indicates no wall
vector<vector<int>> cols(MAX_H + 2, vector<int>(MAX_W + 2, -1)); // -1 indicates no wall

void destroy_wall(int r, int c) {
    if (grid[r][c]) {
        grid[r][c] = false;
        rows[r][c] = -1;
        cols[c][r] = -1;
    }
}

void find_nearest_walls(int r, int c) {
    // Implement logic to find nearest walls in all four directions and destroy walls in between
}

int count_remaining_walls() {
    int remaining = 0;
    for (int i = 1; i <= MAX_H; ++i) {
        for (int j = 1; j <= MAX_W; ++j) {
            if (grid[i][j]) {
                remaining++;
            }
        }
    }
    return remaining;
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    int r, c;
    while (q--) {
        cin >> r >> c;
        destroy_wall(r, c);
        find_nearest_walls(r, c);
    }

    int remaining_walls = count_remaining_walls();
    cout << remaining_walls << endl;

    return 0;
}