#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 10;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> used(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to process cells based on their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], {i, 0}});
        pq.push({A[i][W - 1], {i, W - 1}});
        used[i][0] = used[i][W - 1] = 1;
    }
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], {0, j}});
        pq.push({A[H - 1][j], {H - 1, j}});
        used[0][j] = used[H - 1][j] = 1;
    }

    // Total area of the island
    int totalArea = H * W;

    // Process the cells that will sink each year
    for (int year = 1; year <= Y; year++) {
        int currentYear = year;
        while (!pq.empty() && pq.top().first <= currentYear) {
            auto top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;

            // Check all adjacent cells
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= H || ny >= W || used[nx][ny] == 1) {
                        continue;
                    }
                    if (A[nx][ny] <= currentYear) {
                        used[nx][ny] = 1;
                        pq.push({A[nx][ny], {nx, ny}});
                    }
                }
            }
            totalArea--;
        }
        cout << totalArea << endl;
    }

    return 0;
}