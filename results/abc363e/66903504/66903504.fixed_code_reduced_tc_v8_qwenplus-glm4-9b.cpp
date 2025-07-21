#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> flood(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with the edge cells that are initially under water
    for (int i = 0; i < H; ++i) {
        flood[i][0] = flood[i][W - 1] = true;
        flood[i][W - 1] = true;
        if (A[i][0] <= 0 && !flood[i][0]) {
            q.push({i, 0});
            flood[i][0] = true;
        }
        if (A[i][W - 1] <= 0 && !flood[i][W - 1]) {
            q.push({i, W - 1});
            flood[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        flood[0][j] = flood[H - 1][j] = true;
        if (A[0][j] <= 0 && !flood[0][j]) {
            q.push({0, j});
            flood[0][j] = true;
        }
        if (A[H - 1][j] <= 0 && !flood[H - 1][j]) {
            q.push({H - 1, j});
            flood[H - 1][j] = true;
        }
    }

    int total = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!flood[i][j]) {
                total++;
            }
        }
    }

    while (q.size()) {
        auto h = q.front().first, w = q.front().second;
        q.pop();

        // Explore neighbors
        if (h > 0 && !flood[h - 1][w]) {
            q.push({h - 1, w});
            flood[h - 1][w] = true;
        }
        if (h < H - 1 && !flood[h + 1][w]) {
            q.push({h + 1, w});
            flood[h + 1][w] = true;
        }
        if (w > 0 && !flood[h][w - 1]) {
            q.push({h, w - 1});
            flood[h][w - 1] = true;
        }
        if (w < W - 1 && !flood[h][w + 1]) {
            q.push({h, w + 1});
            flood[h][w + 1] = true;
        }
    }

    while (Y--) {
        cout << total << '\n';
    }

    return 0;
}