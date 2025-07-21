#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int MOD = 1e9 + 7;

struct Node {
    int x,y,val;
    bool operator <(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Node> pq;
    // Add all boundary nodes to the priority queue
    for (int i = 0; i < h; i++) {
        pq.push({i, 0, grid[i][0]});
        pq.push({i, w - 1, grid[i][w - 1]});
    }
    for (int i = 1; i < w - 1; i++) {
        pq.push({0, i, grid[0][i]});
        pq.push({h - 1, i, grid[h - 1][i]});
    }

    int total_area = h * w;
    while (y--) {
        Node node = pq.top(); pq.pop();
        int current_tide = node.val;
        // Update the area of the landmass that remains above the current tide level
        total_area -= count_if(grid.begin(), grid.end(), [&](const vector<int>& row) {
            return min_element(row.begin(), row.end()) >= current_tide;
        });
        // Add the neighboring nodes to the queue if they have not yet sunk
        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i], ny = node.y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] > current_tide) {
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    for (int i = 0; i < y; i++) {
        cout << total_area << endl;
    }
    return 0;
}