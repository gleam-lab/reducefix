#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int sea_level) {
    if (x < 0 || x >= H || y < 0 || y >= W || visited[x][y] || A[x][y] > sea_level) return;
    visited[x][y] = true;
    for (int d = 0; d < 4; ++d) {
        int nx = x + di[d][0], ny = y + di[d][1];
        dfs(nx, ny, sea_level);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize priority queue with all cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            pq.push({A[i][j], {i, j}});
        }
    }

    vector<int> results(Y + 1, 0);
    int count = H * W;

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        while (!pq.empty() && pq.top().first <= sea_level) {
            auto [height, pos] = pq.top(); pq.pop();
            if (visited[pos.first][pos.second]) continue;
            visited[pos.first][pos.second] = true;
            for (int d = 0; d < 4; ++d) {
                int nx = pos.first + di[d][0], ny = pos.second + di[d][1];
                dfs(nx, ny, sea_level);
            }
        }
        results[sea_level] = count;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << results[i] << '\n';
    }

    return 0;
}