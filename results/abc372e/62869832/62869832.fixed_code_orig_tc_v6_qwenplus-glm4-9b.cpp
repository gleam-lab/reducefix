#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
int parent[MAX_N];

void initialize(int n) {
    fill_n(parent, n + 1, -1);
}

int find(int u) {
    if (parent[u] < 0) return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

bool unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (parent[u] > parent[v]) {
            swap(u, v);
        }
        parent[u] += parent[v];
        parent[v] = u;
        return true;
    }
    return false;
}

int main() {
    int n, q;
    cin >> n >> q;

    initialize(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            vector<int> connectedVertices;
            for (int i = 1; i <= n; ++i) {
                if (find(i) == root) {
                    connectedVertices.push_back(i);
                }
            }
            if (k <= connectedVertices.size()) {
                cout << connectedVertices[connectedVertices.size() - k] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}