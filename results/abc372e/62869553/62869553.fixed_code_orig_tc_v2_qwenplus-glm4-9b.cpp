#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> par, rank, size;
    UnionFind(int n) {
        par.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        size[x] += size[y];
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<priority_queue<int>> pq(N + 1);
    vector<int> ans;

    for (int i = 0; i < Q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            uf.unite(u, v);
        } else if (op == 2) {
            int root = uf.find(v);
            if (pq[root].size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(pq[root].top());
                pq[root].pop();
            }
        }
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}