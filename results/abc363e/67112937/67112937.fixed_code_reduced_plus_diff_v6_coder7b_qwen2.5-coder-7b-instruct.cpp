#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Cell {
    int h, x, y;
    bool operator<(const Cell &other) const {
        return h > other.h;
    }
};

void bfs(int start_h) {
    queue<Cell> q;
    priority_queue<Cell> pq;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= start_h) {
                q.push({A[i][j], i, j});
                visited[i][j] = true;
            } else {
                pq.push({A[i][j], i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [h, x, y] = q.front();
        q.pop();

        for (auto &[dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= start_h) {
                visited[nx][ny] = true;
                q.push({A[nx][ny], nx, ny});
            }
        }
    }

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        for (auto &[dx, dy] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= start_h) {
                visited[nx][ny] = true;
                q.push({A[nx][ny], nx, ny});
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

    set<int> heights;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            heights.insert(A[i][j]);
        }
    }

    vector<int> result(Y);
    for (int i = 0; i < Y; ++i) {
        int start_h = *(heights.begin());
        bfs(start_h);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    count++;
                }
            }
        }
        result[Y - 1 - i] = count;
        heights.erase(heights.begin());
    }

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}