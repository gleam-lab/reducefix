#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXY = 100005;

int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int y) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] > y) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (auto &dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > y) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countRemainingArea() {
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j]) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        cout << countRemainingArea() << '\n';
    }

    return 0;
}