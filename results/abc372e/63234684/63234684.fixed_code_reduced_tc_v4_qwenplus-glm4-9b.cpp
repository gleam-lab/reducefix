#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1); // size[i] represents the size of the component containing i
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (size[root_u] < size[root_v]) {
                swap(root_u, root_v);
            }
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }

    void addEdge(int u, int v) {
        unite(u, v);
    }

    void getComponent(int v, priority_queue<int, vector<int>, greater<int>>& pq) {
        int root = find(v);
        for (int u : components[root]) {
            pq.push(u);
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    
    while (q--) {
        int ty, u, v, k;
        cin >> ty >> u >> v;
        if (ty == 1) {
            uf.addEdge(u, v);
        } else if (ty == 2) {
            cin >> k;
            priority_queue<int, vector<int>, greater<int>> pq;
            uf.getComponent(v, pq);
            if (k > pq.size()) {
                cout << -1 << endl;
            } else {
                while (pq.size() > k) pq.pop();
                cout << pq.top() << endl;
            }
        }
    }
    return 0;
}