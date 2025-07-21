#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vec2 {
    int x, y;
    Vec2(int x, int y) : x(x), y(y) {}
};

struct Dir {
    int dx, dy;
    Dir(int dx, int dy) : dx(dx), dy(dy) {}
};

const vector<Dir> dirs = {Dir(0, 1), Dir(1, 0), Dir(0, -1), Dir(-1, 0)};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> seen(H, vector<bool>(W, false));
    vector<vector<bool>> to_sink(H, vector<bool>(W, false));
    queue<Vec2> q;

    // Initialize the queue with the edges of the island
    for (int i = 0; i < H; ++i) {
        q.push(Vec2(i, 0));
        q.push(Vec2(i, W - 1));
        seen[i][0] = seen[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        q.push(Vec2(0, j));
        q.push(Vec2(H - 1, j));
        seen[0][j] = seen[H - 1][j] = true;
    }

    // Simulate each year
    for (int year = 0; year < Y; ++year) {
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            for (const auto& dir : dirs) {
                int i = p.x + dir.dx, j = p.y + dir.dy;
                if (i < 0 || i >= H || j < 0 || j >= W) continue;
                if (seen[i][j]) continue;

                // If the current cell doesn't sink, enqueue it
                if (A[i][j] > year + 1) {
                    seen[i][j] = true;
                    q.push(Vec2(i, j));
                } else {
                    // If the current cell sinks, mark it for sinking next year
                    to_sink[i][j] = true;
                }
            }
        }

        // Update the seen and to_sink arrays based on sinking cells
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (to_sink[i][j]) {
                    seen[i][j] = true;
                    to_sink[i][j] = false;
                }
            }
        }
    }

    // Count the remaining area above sea level
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!seen[i][j]) remaining_area++;
        }
    }

    // Output the result for each year
    for (int year = 0; year < Y; ++year) {
        cout << remaining_area << '\n';
    }

    return 0;
}