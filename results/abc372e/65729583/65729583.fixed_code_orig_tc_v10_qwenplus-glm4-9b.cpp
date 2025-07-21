#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;
vector<int> parent(N);
vector<int> size(N);
vector<vector<int>> adj(N);

void find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) {
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];
        // Add all edges from v's component to u's component
        for (int to : adj[v]) {
            adj[u].push_back(to);
        }
        adj[v].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    fill(parent.begin(), parent.end(), -1);
    fill(size.begin(), size.end(), 0);

    for (int i = 0; i < q; i++) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            unite(u, v);
        } else if (queryType == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = find(v);
            set<int> component = {v};
            for (int to : adj[root]) {
                component.insert(find(to));
            }
            if (component.size() < k) {
                cout << -1 << endl;
            } else {
                cout << *(prev(component.end()) - (k - 1)) + 1 << endl;
            }
        }
    }
    return 0;
}