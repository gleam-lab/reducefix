#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int h) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] <= h) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= h) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> areas(Y);
    for (int i = 0; i < Y; ++i) {
        bfs(i);
        int cnt = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!visited[j][k]) ++cnt;
            }
        }
        areas[i] = cnt;
    }

    for (int i = 0; i < Y; ++i) {
        cout << areas[i] << '\n';
    }

    return 0;
}