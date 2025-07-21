#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXY = 1e5 + 5;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int H, W, Y;
int grid[1005][1005];
bool sunk[1005][1005];
int result[MAXY];

// For each year, how many new cells are sunk
int yearly_sunk[MAXY];

// Union-Find to keep track of connected land areas
int parent[1005 * 1005 + 5], sz[1005 * 1005 + 5];

int idx(int x, int y) {
    return x * W + y;
}

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[y] = x;
    sz[x] += sz[y];
}

signed main() {
    close;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    // Initialize Union-Find
    for (int i = 0; i < H * W + 5; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    // Map height to list of coordinates with that height
    map<int, vector<pii>> heightMap;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            heightMap[grid[i][j]].pb({i, j});

    // Process from lowest height to highest
    for (auto &[h, cells] : heightMap) {
        // First check neighbors to connect
        for (auto [x, y] : cells) {
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !sunk[nx][ny])
                    unite(idx(x, y), idx(nx, ny));
            }
        }
        // Mark these cells as sunk at this height
        for (auto [x, y] : cells)
            sunk[x][y] = true;
    }

    // Total area
    int totalArea = H * W;

    // Count how many cells are sunk at or before each year
    vector<int> heightCount(Y + 2, 0);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (grid[i][j] <= Y)
                heightCount[grid[i][j]]++;

    // Cumulative sum of sunk cells
    for (int i = 1; i <= Y; ++i)
        heightCount[i] += heightCount[i - 1];

    // The final answer is total area minus number of sunk cells
    for (int i = 1; i <= Y; ++i)
        cout << H * W - heightCount[i] << endl;

    return 0;
}