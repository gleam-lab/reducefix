#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 200005;

int parent[N];
vector<vector<int>> adj(N);

int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (adj[x].size() < adj[y].size()) {
            swap(x, y);
        }
        for (int v : adj[x]) {
            parent[v] = y;
            adj[y].push_back(v);
        }
        adj[x].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) parent[i] = i;

    int u, v, k;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        union_sets(u, v);
    }

    int query_count;
    cin >> query_count;
    while (query_count--) {
        cin >> v >> k;
        set<int> values;
        for (int x : adj[find(v)]) {
            values.insert(x);
        }
        if (values.size() < k) {
            cout << -1 << endl;
        } else {
            cout << *prev(values.end()) - k + 1 << endl;
        }
    }

    return 0;
}