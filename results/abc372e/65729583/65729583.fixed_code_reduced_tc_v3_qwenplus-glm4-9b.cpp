#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N), rank(N, 0);

int find(int u) {
    if (u == parent[u]) return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    set<int> graph[N];

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1) {
            unionSets(u, v);
        } else {
            int root_v = find(v);
            if (cmd == 2) {
                if (graph[root_v].size() < v) {
                    cout << -1 << endl;
                } else {
                    auto it = graph[root_v].lower_bound(v);
                    cout << *it << endl;
                }
            }
        }
    }

    return 0;
}