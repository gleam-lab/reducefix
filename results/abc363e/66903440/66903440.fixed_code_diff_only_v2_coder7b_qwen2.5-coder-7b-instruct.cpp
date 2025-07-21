#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAX_Y = 100005;

int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int level) {
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    // Add boundary cells to the queue
    for (int i = 0; i < H; ++i) {
        if (A[i][0] > level || A[i][W-1] > level) {
            q.push({i, 0});
            visited[i][0] = true;
        }
        if (A[i][W-1] > level || A[i][0] > level) {
            q.push({i, W-1});
            visited[i][W-1] = true;
        }
    }

    for (int j = 1; j < W-1; ++j) {
        if (A[0][j] > level || A[H-1][j] > level) {
            q.push({0, j});
            visited[0][j] = true;
        }
        if (A[H-1][j] > level || A[0][j] > level) {
            q.push({H-1, j});
            visited[H-1][j] = true;
        }
    }

    // Perform BFS
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;

        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int total_area = H * W;
    vector<int> remaining_areas(Y);

    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    --total_area;
                }
            }
        }
        remaining_areas[y-1] = total_area;
    }

    for (int y = 0; y < Y; ++y) {
        cout << remaining_areas[y] << endl;
    }

    return 0;
}