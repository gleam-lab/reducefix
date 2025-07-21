#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] > level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = p.first + dx[k], nj = p.second + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] > level) {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    memset(visited, false, sizeof(visited));

    for (int level = 1; level <= Y; ++level) {
        bfs(level);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++count;
                }
            }
        }
        cout << count << endl;
        memset(visited, false, sizeof(visited));
    }

    return 0;
}