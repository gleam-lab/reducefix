#include<bits/stdc++.h>
using namespace std;

int H, W, Y;
vector<vector<int>> A, F;
vector<queue<pair<int, int>>> Q;

void bfs(int startElev) {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == startElev) {
                q.push({i, j});
                F[i][j] = false;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] > startElev && F[nx][ny]) {
                F[nx][ny] = false;
                Q[A[nx][ny]].push({nx, ny});
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    F.resize(H, vector<bool>(W, true));
    Q.resize(100000);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int currYear = 0;
    while (currYear < min(Y, 100000) && !F[0][0]) {
        bfs(A[0][0]);
        currYear++;
    }

    for (int i = 0; i < Y; ++i) {
        // Output the area that remains above sea level after 'i' years
        int remainingArea = 0;
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                if (F[x][y]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}