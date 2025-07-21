#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> PIII; // pair of elevation, pair of coordinates

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> height(H, vector<int>(W));
    vector<vector<int>> sink(H, vector<int>(W, INT_MAX));

    // Read the elevation matrix
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> height[i][j];
        }
    }

    // Priority queue to process cells by their sinking order
    priority_queue<PIII, vector<PIII>, greater<PIII>> pq;

    // Initialize the priority queue with boundary and flat cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || height[i][j] <= height[i][0]) {
                sink[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    // Process the queue
    while (!pq.empty()) {
        PIII front = pq.top();
        pq.pop();
        int H = front.first;
        int r = front.second.first;
        int c = front.second.second;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nr = r + i;
                int nc = c + j;
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (height[nr][nc] <= H) {
                    sink[nr][nc] = min(sink[nr][nc], H);
                    pq.push({height[nr][nc], {nr, nc}});
                }
            }
        }
    }

    // Calculate the area above the sea level for each year
    for (int y = 1; y <= Y; ++y) {
        int remainingArea = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (y < sink[i][j]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << '\n';
    }

    return 0;
}