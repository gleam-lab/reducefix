#include <bits/stdc++.h>

using namespace std;

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

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Push all border cells into the priority queue
    for (int i = 0; i < H; ++i) {
        if (!visited[i][0]) {
            pq.push({A[i][0], {i, 0}});
            visited[i][0] = true;
        }
        if (!visited[i][W - 1]) {
            pq.push({A[i][W - 1], {i, W - 1}});
            visited[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!visited[0][j]) {
            pq.push({A[0][j], {0, j}});
            visited[0][j] = true;
        }
        if (!visited[H - 1][j]) {
            pq.push({A[H - 1][j], {H - 1, j}});
            visited[H - 1][j] = true;
        }
    }

    int remaining = H * W;
    vector<int> result(Y);

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int h = current.first;
            int x = current.second.first;
            int y = current.second.second;
            --remaining;
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        result[year - 1] = remaining;
    }

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}