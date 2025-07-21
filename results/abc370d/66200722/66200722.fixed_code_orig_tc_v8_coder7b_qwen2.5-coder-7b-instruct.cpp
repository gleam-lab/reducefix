#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 400005;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        rank[u] += rank[v];
    }
};

struct Line {
    int type, x1, x2, y1, y2;
    Line(int type, int x1, int x2, int y1, int y2) : type(type), x1(x1), x2(x2), y1(y1), y2(y2) {}
    bool operator<(const Line& other) const {
        if (type != other.type) return type < other.type;
        if (type == 0) return x1 < other.x1;
        else return y1 < other.y1;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf(H + W);

    vector<Line> lines;
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R, --C;

        if (!lines.empty()) {
            int prev_x = lines.back().x2;
            int prev_y = lines.back().y2;
            lines.emplace_back(0, prev_x, C, prev_y, R);
        }

        lines.emplace_back(1, C, C + 1, R, R + 1);
        lines.emplace_back(0, C + 1, C + 1, R, R + 1);
    }

    sort(lines.begin(), lines.end());

    int cnt = 0;
    for (const auto& line : lines) {
        if (line.type == 0) {
            int u = uf.find(line.x1);
            int v = uf.find(line.x2);
            if (u != v) {
                uf.unite(u, v);
                ++cnt;
            }
        } else {
            int u = uf.find(line.y1);
            int v = uf.find(line.y2);
            if (u != v) {
                uf.unite(u, v);
                ++cnt;
            }
        }
    }

    cout << (H * W - cnt) << endl;

    return 0;
}