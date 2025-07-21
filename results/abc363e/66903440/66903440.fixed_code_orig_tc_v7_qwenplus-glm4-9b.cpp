#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int i, j;
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> F(H, vector<int>(W, 0));
    queue<Pair> q;
    int totalArea = H * W;

    // Initialize the queue with the borders of the island
    for (int i = 0; i < H; ++i) {
        q.push({i, 0}); // Left border
        q.push({i, W - 1}); // Right border
    }
    for (int j = 1; j < W - 1; ++j) {
        q.push({0, j}); // Top border
        q.push({H - 1, j}); // Bottom border
    }
    while (!q.empty()) {
        Pair p = q.front();
        q.pop();
        int x = p.i;
        int y = p.j;
        if (F[x][y] == 0) continue;
        F[x][y] = 0;
        --totalArea;
        for (int k = 0; k < 4; ++k) {
            int nx = x + (k == 0 ? -1 : (k == 1 ? 1 : 0));
            int ny = y + (k == 2 ? -1 : (k == 3 ? 1 : 0));
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (F[nx][ny] == 1) {
                    F[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int y = 0; y < Y; ++y) {
        // Reset the F matrix for the next year's simulation
        fill(F[0].begin(), F[0].end(), 1);
        fill(F[H-1].begin(), F[H-1].end(), 1);
        for (int j = 0; j < W; ++j) {
            F[0][j] = F[H-1][j] = 0;
        }
        for (int i = 1; i < H - 1; ++i) {
            F[i][0] = F[i][W-1] = 0;
        }
        // Add new sections that will sink in this year's simulation
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] == y + 1 && (i == 0 || i == H - 1 || j == 0 || j == W - 1)) {
                    q.push({i, j});
                    F[i][j] = 0;
                    --totalArea;
                }
            }
        }
        // Perform the BFS for this year's simulation
        while (!q.empty()) {
            Pair p = q.front();
            q.pop();
            int x = p.i;
            int y = p.j;
            for (int k = 0; k < 4; ++k) {
                int nx = x + (k == 0 ? -1 : (k == 1 ? 1 : 0));
                int ny = y + (k == 2 ? -1 : (k == 3 ? 1 : 0));
                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if (F[nx][ny] == 1) {
                        F[nx][ny] = 0;
                        q.push({nx, ny});
                        --totalArea;
                    }
                }
            }
        }
        cout << totalArea << endl;
    }

    return 0;
}