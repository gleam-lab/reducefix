#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
int H, W, Y;

struct Cell {
    int x, y, height;
    bool operator<(const Cell& other) const {
        return height > other.height;
    }
};

void bfs(int sea_level) {
    queue<Cell> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] <= sea_level) {
                visited[i][j] = true;
                q.push({i, j, A[i][j]});
            }
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!q.empty()) {
        auto [x, y, h] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                visited[nx][ny] = true;
                q.push({nx, ny, A[nx][ny]});
            }
        }
    }
}

int countRemainingLand() {
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Cell> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            pq.push({i, j, A[i][j]});
        }
    }

    for (int i = 0; i < Y; ++i) {
        while (!pq.empty() && pq.top().height <= i) {
            auto [x, y, h] = pq.top();
            pq.pop();
            bfs(i);
        }
        cout << countRemainingLand() << endl;
    }

    return 0;
}