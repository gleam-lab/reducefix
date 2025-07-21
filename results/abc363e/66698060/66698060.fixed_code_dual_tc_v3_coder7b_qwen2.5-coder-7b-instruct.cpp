#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
long long room[MAXN][MAXN];

struct Node {
    long long height, x, y;
    bool operator<(const Node& other) const {
        return height > other.height;
    }
};

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(long long threshold) {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;
    
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0] && room[i][0] <= threshold) {
            q.push({i, 0});
            visited[i][0] = true;
        }
        if (!visited[i][W - 1] && room[i][W - 1] <= threshold) {
            q.push({i, W - 1});
            visited[i][W - 1] = true;
        }
    }

    for (int j = 1; j < W - 1; ++j) {
        if (!visited[0][j] && room[0][j] <= threshold) {
            q.push({0, j});
            visited[0][j] = true;
        }
        if (!visited[H - 1][j] && room[H - 1][j] <= threshold) {
            q.push({H - 1, j});
            visited[H - 1][j] = true;
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && room[nx][ny] <= threshold) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j]) {
                room[i][j] = -1; // Mark as submerged
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> room[i][j];
        }
    }

    long long totalLand = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            totalLand += (room[i][j] != -1);
        }
    }

    for (int t = 1; t <= Y; ++t) {
        bfs(t);
        long long remainingLand = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (room[i][j] != -1) {
                    remainingLand++;
                }
            }
        }
        cout << remainingLand << endl;
    }

    return 0;
}