#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));

struct Node {
    int h, x, y;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

void bfs(vector<vector<bool>>& visited, priority_queue<Node>& pq) {
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int h = cur.h, x = cur.x, y = cur.y;
        if (x >= 0 && x < H && y >= 0 && y < W && !visited[x][y]) {
            visited[x][y] = true;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= h) {
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Node> pq;
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
    }
    for (int j = 1; j < W-1; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H-1][j], H-1, j});
    }

    vector<int> res(Y);
    for (int t = 0; t < Y; ++t) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        bfs(visited, pq);

        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++cnt;
                }
            }
        }
        res[t] = cnt;
    }

    for (int i = 0; i < Y; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}