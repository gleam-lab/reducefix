#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

struct DSU {
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n) : parent(n), size(n, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> sunk(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    DSU dsu(H * W);
    int remaining = H * W;

    vector<int> res(Y + 1);
    for (int y = 1; y <= Y; y++) {
        while (!pq.empty() && pq.top().first <= y) {
            auto [val, pos] = pq.top();
            pq.pop();
            int i = pos.first;
            int j = pos.second;
            remaining--;

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (!sunk[ni][nj]) {
                    sunk[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        res[y] = remaining;
    }

    for (int y = 1; y <= Y; y++) {
        cout << res[y] << '\n';
    }

    return 0;
}