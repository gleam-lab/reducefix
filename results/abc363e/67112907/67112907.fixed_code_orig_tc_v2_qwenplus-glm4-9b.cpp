#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], {i, 0}});
        visited[i][0] = true;
        if (i < H - 1) pq.push({A[i][W - 1], {i, W - 1}});
        visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], {0, j}});
        visited[0][j] = true;
        if (j < W - 1) pq.push({A[H - 1][j], {H - 1, j}});
        visited[H - 1][j] = true;
    }

    int remainingArea = H * W; // Start with the total area

    for (int year = 0; year < Y; year++) {
        int newSubmergedArea = 0;
        while (!pq.empty()) {
            int h = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (h <= year) { // If the current elevation is less than or equal to the sea level
                newSubmergedArea += 1;
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    if (nx < 0 || nx >= H) continue;
                    for (int dy = -1; dy <= 1; dy++) {
                        int ny = y + dy;
                        if (ny < 0 || ny >= W) continue;
                        if (!visited[nx][ny] && A[nx][ny] <= year) {
                            visited[nx][ny] = true;
                            pq.push({A[nx][ny], {nx, ny}});
                        }
                    }
                }
            }
        }
        remainingArea -= newSubmergedArea; // Subtract the area that has sunk into the sea
        cout << remainingArea << '\n';
    }

    return 0;
}