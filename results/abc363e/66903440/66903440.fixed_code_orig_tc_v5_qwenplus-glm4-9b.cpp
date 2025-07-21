#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Position {
    int r, c;
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Directions for adjacent cells (up, down, left, right)
    vector<Position> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<Position> sinkingQueue;
    bool sink[H][W];

    // Initialize sinking areas
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (r == 0 || r == H - 1 || c == 0 || c == W - 1) {
                sinkingQueue.push({r, c});
            }
        }
    }

    // Perform the flooding simulation
    for (int year = 0; year < Y; ++year) {
        int remainingArea = 0;
        while (!sinkingQueue.empty()) {
            auto pos = sinkingQueue.front();
            sinkingQueue.pop();

            bool canSink = true;
            for (auto dir : directions) {
                int nr = pos.r + dir.r;
                int nc = pos.c + dir.c;
                if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                    if (A[nr][nc] <= year && A[nr][nc] > A[pos.r][pos.c]) {
                        canSink = false;
                        sinkingQueue.push({nr, nc});
                    }
                    if (A[nr][nc] > year && !sink[nr][nc]) {
                        remainingArea++;
                    }
                }
            }

            if (canSink) {
                for (auto dir : directions) {
                    int nr = pos.r + dir.r;
                    int nc = pos.c + dir.c;
                    if (nr >= 0 && nr < H && nc >= 0 && nc < W && !sink[nr][nc]) {
                        A[nr][nc]--;
                        sink[nr][nc] = true;
                        sinkingQueue.push({nr, nc});
                    }
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}