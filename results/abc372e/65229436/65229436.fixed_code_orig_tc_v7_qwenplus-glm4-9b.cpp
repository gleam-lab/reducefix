#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int size) : parent(size, -1) {}

    int findRoot(int vertex) {
        if (parent[vertex] < 0) return vertex;
        parent[vertex] = findRoot(parent[vertex]);
        return parent[vertex];
    }

    bool unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return false;
        if (parent[u] > parent[v]) swap(u, v);
        parent[u] += parent[v];
        parent[v] = u;
        return true;
    }

    int size(int vertex) {
        return -parent[findRoot(vertex)];
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<set<int>> components(N);
    vector<int> answers;

    for (int i = 0; i < N; ++i) {
        components[i].insert(i);
    }

    for (int i = 0; i < Q; ++i) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) { // Add edge
            int u, v;
            cin >> u >> v;
            --u; --v;

            if (uf.findRoot(u) != uf.findRoot(v)) {
                uf.unite(u, v);
            }

            components[uf.findRoot(u)] = components[uf.findRoot(v)];
        } else if (queryType == 2) { // Query k-th largest
            int v, k;
            cin >> v >> k;
            --v;

            set<int>& comp = components[uf.findRoot(v)];
            if (comp.size() < k) {
                answers.push_back(-1);
            } else {
                auto it = next(comp.upper_bound(v), k - 2);
                answers.push_back(*it);
            }
        }
    }

    for (int answer : answers) {
        cout << answer + 1 << endl;
    }

    return 0;
}