#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;

vector<int> adj[N];
vector<int> size(N, 1);

int findRoot(int u) {
    if (u != adj[u].back()) {
        int root = findRoot(adj[u].back());
        adj[u].back() = root;
        return root;
    }
    return u;
}

void unite(int u, int v) {
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) {
            swap(rootU, rootV);
        }
        adj[rootU].insert(adj[rootU].end(), adj[rootV].begin(), adj[rootV].end());
        size[rootU] += size[rootV];
        adj[rootV].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        adj[i].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            vector<int> connected;
            for (int u : adj[v]) {
                if (u != v) {
                    connected.push_back(u);
                }
            }
            if (k > connected.size()) {
                cout << -1 << endl;
            } else {
                sort(connected.rbegin(), connected.rend());
                cout << connected[k - 1] << endl;
            }
        }
    }
    return 0;
}