#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
bool visited[MAXN][MAXN];

void bfs(int startRow, int startCol, int seaLevel) {
    queue<pair<int, int>> q;
    q.emplace(startRow, startCol);
    visited[startRow][startCol] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int newRow = row + dx[dir];
            int newCol = col + dy[dir];

            if (newRow < 0 || newRow >= H || newCol < 0 || newCol >= W) continue;
            if (visited[newRow][newCol]) continue;
            if (A[newRow][newCol] <= seaLevel) {
                visited[newRow][newCol] = true;
                q.emplace(newRow, newCol);
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

    for (int seaLevel = 1; seaLevel <= Y; ++seaLevel) {
        memset(visited, false, sizeof(visited));

        // Check boundary conditions
        for (int i = 0; i < H; ++i) {
            if (A[i][0] > seaLevel) bfs(i, 0, seaLevel);
            if (A[i][W-1] > seaLevel) bfs(i, W-1, seaLevel);
        }
        for (int j = 0; j < W; ++j) {
            if (A[0][j] > seaLevel) bfs(0, j, seaLevel);
            if (A[H-1][j] > seaLevel) bfs(H-1, j, seaLevel);
        }

        // Count remaining land
        int remainingLand = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] > seaLevel) {
                    remainingLand++;
                }
            }
        }

        cout << remainingLand << endl;
    }

    return 0;
}