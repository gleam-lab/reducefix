#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize visited matrix and priority queue
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Push all boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    int remaining = H * W;

    // We'll output answers for each year from 1 to Y
    vector<int> ans(Y + 2, 0);  // ans[i] is the area at year i

    // We need to track when a cell gets submerged
    vector<vector<int>> sink_year(H, vector<int>(W, -1));

    // Process using Dijkstra-like BFS with sea level rising
    int current_year = 0;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        // If height > current sea level (h > current_year), we stop until next year
        while (current_year < h) {
            current_year++;
            remaining -= ans[current_year];  // ans will store how many cells sink at this year
        }

        if (sink_year[x][y] != -1)
            continue;

        sink_year[x][y] = current_year;
        ans[current_year]++;

        // Propagate to neighbors
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Now compute cumulative answer
    int cur_area = H * W;
    for (int i = 1; i <= Y; ++i) {
        cur_area -= ans[i];
        cout << cur_area << "\n";
    }

    return 0;
}