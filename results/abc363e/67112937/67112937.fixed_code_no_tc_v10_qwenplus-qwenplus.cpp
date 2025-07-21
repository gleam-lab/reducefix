#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    // Priority queue to process cells in increasing order of elevation
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            visited[i][0] = true;
            pq.emplace(A[i][0], i, 0);
        }
        if (!visited[i][W-1]) {
            visited[i][W-1] = true;
            pq.emplace(A[i][W-1], i, W-1);
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!visited[0][j]) {
            visited[0][j] = true;
            pq.emplace(A[0][j], 0, j);
        }
        if (!visited[H-1][j]) {
            visited[H-1][j] = true;
            pq.emplace(A[H-1][j], H-1, j);
        }
    }

    int remaining = H * W;
    vector<int> answer(Y + 2); // We'll store results here and then print them
    answer[0] = remaining;

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    
    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        // This cell was already processed
        if (sunk[x][y]) continue;
        
        // Process this cell: it will be submerged at sea level 'height'
        sunk[x][y] = true;
        --remaining;

        // Push neighbors into the queue if not yet processed
        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(A[nx][ny], nx, ny);
            }
        }
    }

    // Now we need to build our output using offline processing
    vector<int> heights(Y + 2);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= Y) {
                heights[A[i][j]]++;
            }
        }
    }

    // Build prefix sum from high to low
    for (int y = 1; y <= Y; ++y) {
        answer[y] = answer[y-1] - heights[y];
    }

    // Output results
    for (int y = 1; y <= Y) {
        cout << answer[y] << "\n";
    }

    return 0;
}