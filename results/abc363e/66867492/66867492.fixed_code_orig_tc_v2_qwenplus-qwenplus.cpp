#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, l, r) for (int i = (l); i <= (int)(r); ++i)
#define per(i, n) for (int i = (n)-1; i >= 0; --i)

using Pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    int components;

    UnionFind(int n) : parent(n), size(n, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (size[rootX] < size[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        components--;
        return true;
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    map<int, vector<Pii>> heightMap;
    rep(i, H) rep(j, W) heightMap[A[i][j]].emplace_back(i, j);

    // Create a grid to mark whether a cell has been submerged
    vector<vector<bool>> submerged(H, vector<bool>(W, false));

    // We'll process from lowest to highest elevation
    UnionFind uf(H * W);
    vector<bool> isSubmerged(H * W, false);
    vector<int> cellId(H, vector<int>(W));
    rep(i, H) rep(j, W) cellId[i][j] = i * W + j;

    int totalArea = H * W;
    vi answer(Y + 2, totalArea); // answer[year]

    // For handling the outer sea connection
    int sea_node = H * W;
    UnionFind uf_ext(H * W + 1);
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

    for (auto& [height, cells] : heightMap) {
        for (auto [x, y] : cells) {
            submerged[x][y] = true;
            int id = cellId[x][y];

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && submerged[nx][ny]) {
                    uf_ext.unite(cellId[nx][ny], id);
                } else if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    uf_ext.unite(sea_node, id);
                }
            }
        }

        // Update area after this height is processed
        for (auto [x, y] : cells) {
            int id = cellId[x][y];
            if (uf_ext.find(id) == uf_ext.find(sea_node)) {
                totalArea--;
            }
        }

        // Save result for years up to this height
        for (int year = max(1, answer.size() - 1); year <= height; year++) {
            if (year > Y)
                break;
            answer[year] = totalArea;
        }
    }

    // Fill in any missing values
    for (int i = 1; i <= Y; i++) {
        if (answer[i] == 0 && i > 1)
            answer[i] = answer[i - 1];
    }

    // Output results
    for (int i = 1; i <= Y; i++)
        cout << answer[i] << "\n";

    return 0;
}