#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int H, W, Y;
vector<vector<int>> grid;

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val < a.val;
    }
};

void process(int sea_level) {
    // Mark all cells to be potentially visited
    vector<vector<bool>> to_visit(H, vector<bool>(W, false));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Enqueue all edges of the grid that are at the current sea level
    for (int i = 0; i < H; ++i) {
        to_visit[i][0] = to_visit[i][W - 1] = true;
        pq.push({i, 0, grid[i][0]});
        pq.push({i, W - 1, grid[i][W - 1]});
    }
    for (int i = 1; i < W - 1; ++i) {
        to_visit[0][i] = to Visit[h - 1][i] = true;
        pq.push({0, i, grid[0][i]});
        pq.push({h - 1, i, grid[h - 1][i]});
    }

    // Process the queue
    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !to_visit[nx][ny] && grid[nx][ny] > sea_level) {
                to_visit[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    // Count the area not visited (not submerged)
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!to_visit[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the result for the current year
    cout << remaining_area << endl;
}

signed main() {
    close;
    cin >> H >> W >> Y;
    grid.resize(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int year = 1; year <= Y; ++year) {
        process(year);
    }

    return 0;
}