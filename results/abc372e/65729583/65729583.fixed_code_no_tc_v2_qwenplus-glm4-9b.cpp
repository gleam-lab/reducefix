#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N);
vector<int> size(N);
vector<set<int>> adj(N);

void initialize() {
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return;

    if (size[u] < size[v]) {
        swap(u, v);
    }

    parent[v] = u;
    size[u] += size[v];
}

void add_edge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

int main() {
    int n, q;
    cin >> n >> q;
    initialize();

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            set<int> connected_vertices = adj[find(v)];
            if (k > connected_vertices.size()) {
                cout << -1 << endl;
            } else {
                cout << *next(connected_vertices.begin(), k - 1) << endl;
            }
        }
    }

    return 0;
}