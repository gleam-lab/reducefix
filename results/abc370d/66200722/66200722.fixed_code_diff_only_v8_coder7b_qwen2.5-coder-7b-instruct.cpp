#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX = 400005;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(MAX);
    map<int, int> s[MAX];
    map<int, int> t[MAX];

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!s[r].count(c)) {
            s[r][c] = uf.find(r * w + c);
            t[c][r] = uf.find(r * w + c);
            continue;
        }

        int id = s[r][c];
        int min_r = *begin(s[id]).first;
        int max_r = *rbegin(s[id]).first;
        int min_c = *begin(t[id]).first;
        int max_c = *rbegin(t[id]).first;

        if (min_r > 0 && !s[min_r - 1].count(c)) {
            s[min_r - 1][c] = id;
            t[c][min_r - 1] = id;
            uf.unite(id, min_r * w + c);
        }
        if (max_r < h - 1 && !s[max_r + 1].count(c)) {
            s[max_r + 1][c] = id;
            t[c][max_r + 1] = id;
            uf.unite(id, (max_r + 1) * w + c);
        }
        if (min_c > 0 && !t[min_c - 1].count(r)) {
            t[min_c - 1][r] = id;
            s[r][min_c - 1] = id;
            uf.unite(id, r * w + min_c - 1);
        }
        if (max_c < w - 1 && !t[max_c + 1].count(r)) {
            t[max_c + 1][r] = id;
            s[r][max_c + 1] = id;
            uf.unite(id, r * w + max_c + 1);
        }
    }

    long long ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i].count(j)) {
                int root = uf.find(i * w + j);
                if (root == i * w + j) {
                    ans += (long long)(max_i[root] - min_i[root] + 1) *
                           (max_j[root] - min_j[root] + 1);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}