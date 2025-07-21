#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Total number of cells
    long long total_walls = 1LL * H * W;

    // Map to store whether a wall exists at each cell
    vector<vector<bool>> wall(H, vector<bool>(W, true));

    // DSU parents for:
    // - Left and Right per row
    // - Up and Down per column
    vector<vector<int>> left(H, vector<int>(W));
    vector<vector<int>> right(H, vector<int>(W));
    vector<vector<int>> up(H, vector<int>(W));
    vector<vector<int>> down(H, vector<int>(W));

    // Initialize DSU structures
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            left[i][j] = j - 1;
            right[i][j] = j + 1;
            up[i][j] = i - 1;
            down[i][j] = i + 1;
        }
    }

    // Function to find next available wall to the left
    auto find_left = [&](int r, int c) -> int {
        while (left[r][c] >= 0 && !wall[r][left[r][c]]) {
            left[r][c] = left[r][left[r][c]];
        }
        return left[r][c];
    };

    // Function to find next available wall to the right
    auto find_right = [&](int r, int c) -> int {
        while (right[r][c] < W && !wall[r][right[r][c]]) {
            right[r][c] = right[r][right[r][c]];
        }
        return right[r][c];
    };

    // Function to find next available wall above
    auto find_up = [&](int r, int c) -> int {
        while (up[r][c] >= 0 && !wall[up[r][c]][c]) {
            up[r][c] = up[up[r][c]][c];
        }
        return up[r][c];
    };

    // Function to find next available wall below
    auto find_down = [&](int r, int c) -> int {
        while (down[r][c] < H && !wall[down[r][c]][c]) {
            down[r][c] = down[down[r][c]][c];
        }
        return down[r][c];
    };

    long long destroyed = 0;

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R, --C;

        if (wall[R][C]) {
            // Already has a wall: destroy it
            wall[R][C] = false;
            ++destroyed;
        } else {
            // No wall here: try destroying first visible walls in all directions
            int dirs[4] = {0};

            // Try in each direction
            if (find_up(R, C) >= 0) {
                int u = find_up(R, C);
                wall[u][C] = false;
                ++destroyed;
                up[R][C] = u;
                up[u][C] = up[R][C] = up[u][C]; // Compress path
            }
            if (find_down(R, C) < H) {
                int d = find_down(R, C);
                wall[d][C] = false;
                ++destroyed;
                down[R][C] = d;
                down[d][C] = down[R][C] = down[d][C];
            }
            if (find_left(R, C) >= 0) {
                int l = find_left(R, C);
                wall[R][l] = false;
                ++destroyed;
                left[R][C] = l;
                left[R][l] = left[R][C] = left[R][l];
            }
            if (find_right(R, C) < W) {
                int r = find_right(R, C);
                wall[R][r] = false;
                ++destroyed;
                right[R][C] = r;
                right[R][r] = right[R][C] = right[R][r];
            }
        }
    }

    cout << total_walls - destroyed << endl;
}