#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second

const int MAX = 1005;
int H, W, Y;
int height[MAX][MAX];
int sink_year[MAX][MAX];

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Cell {
    int h, x, y;
    bool operator<(const Cell &o) const {
        return h > o.h;
    }
};

bool vis[MAX][MAX];

void solve() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> height[i][j];

    // Initialize sink_year to max possible year
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            sink_year[i][j] = Y + 1;

    priority_queue<Cell> pq;

    // Push boundary cells into the queue and mark their sink year as their own height
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                sink_year[i][j] = height[i][j];
                pq.push({height[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    // Multi-source BFS with min-heap (priority queue)
    while (!pq.empty()) {
        Cell cur = pq.top();
        pq.pop();

        int cx = cur.x, cy = cur.y, ch = cur.h;

        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            // If this cell is not visited yet
            if (!vis[nx][ny]) {
                // The new sink year is min(current sink year of neighbor, current cell's height)
                // Because water can propagate through connected cells <= current sea level
                int new_sink_year = min(sink_year[nx][ny], ch);
                sink_year[nx][ny] = new_sink_year;
                pq.push({new_sink_year, nx, ny});
                vis[nx][ny] = true;
            } else {
                // Already visited, but we might have a better (earlier) sink year
                if (sink_year[nx][ny] > ch) {
                    sink_year[nx][ny] = ch;
                    pq.push({ch, nx, ny});
                }
            }
        }
    }

    // Count how many cells are sunk each year
    vector<int> sunk(Y + 2, 0);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int s = sink_year[i][j];
            if (s <= Y)
                sunk[s]++;
        }
    }

    // Cumulative sum of sunk cells
    vector<int> area(Y + 2, 0);
    for (int i = 1; i <= Y; ++i) {
        sunk[i] += sunk[i - 1];
        area[i] = H * W - sunk[i];
    }

    for (int i = 1; i <= Y; ++i)
        cout << area[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}