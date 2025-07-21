#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];

void bfs(int level) {
    queue<pair<int, int>> q;
    bool visited[MAXN][MAXN] = {false};
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (A[i][j] > level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                if (abs(dx) != abs(dy)) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= level && !visited[nx][ny]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
    }

    // Calculate remaining land area
    int count = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (A[i][j] > level && visited[i][j])
                count++;
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    sort(A[0], A[0] + W);
    vector<int> levels(Y);
    for (int i = 0; i < Y; ++i)
        levels[i] = A[0][i];

    for (int level : levels)
        bfs(level);

    return 0;
}