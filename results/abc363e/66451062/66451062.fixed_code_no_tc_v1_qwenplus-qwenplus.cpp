#include <bits/stdc++.h>
using namespace std;
#define int long long

int H, W, Y;
const int MAX = 1005;
int grid[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Cell {
    int r, c, val;
    bool operator<(const Cell& o) const {
        return val > o.val;
    }
};

priority_queue<Cell> pq;

int remaining;

void process(int sea_level) {
    while (!pq.empty() && pq.top().val <= sea_level) {
        Cell cur = pq.top(); pq.pop();
        if (visited[cur.r][cur.c]) continue;
        visited[cur.r][cur.c] = true;
        remaining--;

        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dx[i];
            int nc = cur.c + dy[i];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                pq.push({nr, nc, grid[nr][nc]});
                visited[nr][nc] = true;  // Mark as enqueued to avoid duplicates
                remaining--;
                visited[nr][nc] = false; // Revert because it's not truly "processed" yet
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    remaining = H * W;

    // Initialize the border cells in the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    pq.push({i, j, grid[i][j]});
                }
            }
        }
    }

    // We need to keep track of how many cells are submerged at each year
    vector<int> result(Y + 2);  // result[i] is area above sea level after i years
    result[0] = H * W;

    for (int year = 1; year <= Y; ++year) {
        process(year);
        result[year] = remaining;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << result[year] << '\n';
    }

    return 0;
}