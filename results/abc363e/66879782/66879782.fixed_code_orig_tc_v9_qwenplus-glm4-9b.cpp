// Assuming we have defined the variables H, W, Y, and A as in the problem statement.

queue<pair<int, int>> q; // queue to perform BFS
vector<vector<bool>> visited(H, vector<bool>(W, false)); // visited matrix to keep track of visited sections

// Place all boundary sections in the queue
for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
        if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && !visited[i][j]) {
            visited[i][j] = true;
            q.push({i, j});
        }
    }
}

// Perform BFS to propagate the elevation
while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
        int ni = i + directions[dir][0], nj = j + directions[dir][1];
        if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
            visited[ni][nj] = true;
            A[ni][nj] = min(A[ni][nj], A[i][j]);
            q.push({ni, nj});
        }
    }
}

// Now A contains the elevation of each section after 1 year of rise
// Calculate the remaining area for each year by checking if A[ni][nj] <= Y