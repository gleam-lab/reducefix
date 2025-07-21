#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_H = 1000;
constexpr int MAX_W = 1000;
constexpr int MAX_Y = 100000;

int H, W, Y;
int A[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];

struct Cell {
    int h;
    int x;
    int y;
};

// For priority queue to process lowest elevation first
priority_queue<Cell, vector<Cell>, function<bool(Cell, Cell)>> pq([](Cell a, Cell b) {
    return a.h > b.h;
});

int ans;

void init() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1)) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    ans = H * W;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    init();

    vector<int> output(Y + 2); // Store answers for all years
    int year = 1;

    while (!pq.empty() && year <= Y) {
        while (!pq.empty() && pq.top().h <= year) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (!visited[x][y]) {
                --ans;
                visited[x][y] = true;
            }
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                    --ans;
                }
            }
        }
        output[year] = ans;
        ++year;
    }

    while (year <= Y) {
        output[year] = ans;
        ++year;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << output[i] << '\n';
    }

    return 0;
}