#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) 
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> sink(H, vector<int>(W, Y + 1));

    // Initialize the priority queue with edge cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                pq.push({A[i][j], {i, j}});
                sink[i][j] = 0;
            }
        }
    }

    // Perform the flood fill
    while (!pq.empty()) {
        auto [H, {i, j}] = pq.top();
        pq.pop();
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                int ni = i + di, nj = j + dj;
                if (ni < 0 || ni >= H || nj < 0 || nj >= W || visited[ni][nj]) continue;
                if (A[ni][nj] <= H && sink[ni][nj] > sink[i][j] + di * dj) {
                    visited[ni][nj] = true;
                    sink[ni][nj] = sink[i][j] + di * dj;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
    }

    // Calculate and output the remaining area
    for (int y = 0; y < Y; y++) {
        int remaining = 0;
        for (int i = 0; i < H; i++) 
            for (int j = 0; j < W; j++)
                if (!visited[i][j] && A[i][j] > y + 1) remaining++;
        cout << remaining << "\n";
    }

    return 0;
}