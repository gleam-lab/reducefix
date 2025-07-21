#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Node {
    int h, x, y;
    bool operator<(const Node& other) const {
        return h > other.h;
    }
};

void bfs(int sea_level) {
    queue<Node> q;
    for (int i = 0; i < H; ++i) {
        if (A[i][0] > sea_level) {
            q.push({A[i][0], i, 0});
            visited[i][0] = true;
        }
        if (A[i][W-1] > sea_level) {
            q.push({A[i][W-1], i, W-1});
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (A[0][j] > sea_level) {
            q.push({A[0][j], 0, j});
            visited[0][j] = true;
        }
        if (A[H-1][j] > sea_level) {
            q.push({A[H-1][j], H-1, j});
            visited[H-1][j] = true;
        }
    }

    while (!q.empty()) {
        auto [h, x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
            if (A[nx][ny] <= sea_level) continue;
            visited[nx][ny] = true;
            q.push({A[nx][ny], nx, ny});
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

    for (int i = 0; i < Y; ++i) {
        fill(visited[0], visited[H], false);
        bfs(i);
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) ++remaining_area;
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}