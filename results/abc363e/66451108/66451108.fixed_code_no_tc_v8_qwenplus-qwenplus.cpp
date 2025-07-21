#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAXH = 1005;
const int MAXW = 1005;
const int MAXY = 1e5 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    int grid[MAXH][MAXW];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    bool vis[MAXH][MAXW] = {};
    priority_queue<Node> pq;

    // Initialize the border as initially submerged
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                if (!vis[i][j]) {
                    vis[i][j] = true;
                    pq.push({i, j, grid[i][j]});
                }
            }
        }
    }

    int res = h * w;
    vector<int> year_area(y + 2, res); // Store area for each year, default to full

    priority_queue<Node> q = pq; // Copy of initial queue

    // We'll simulate up to max elevation or Y years, whichever is smaller
    int max_elevation = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            max_elevation = max(max_elevation, grid[i][j]);
        }
    }

    int limit_year = min(y, (int)1e5);

    // Use a copy of the priority queue to avoid modifying original
    priority_queue<Node> simulation_q = pq;
    bool sim_vis[MAXH][MAXW];
    memcpy(sim_vis, vis, sizeof(sim_vis));

    int current_area = res;
    for (int level = 1; level <= limit_year; level++) {
        while (!simulation_q.empty() && simulation_q.top().val <= level) {
            Node cur = simulation_q.top(); simulation_q.pop();
            if (!sim_vis[cur.x][cur.y]) continue;
            current_area--;
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !sim_vis[nx][ny]) {
                    sim_vis[nx][ny] = true;
                    simulation_q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        year_area[level] = current_area;
    }

    for (int i = 1; i <= y; i++) {
        cout << year_area[i] << endl;
    }

    return 0;
}