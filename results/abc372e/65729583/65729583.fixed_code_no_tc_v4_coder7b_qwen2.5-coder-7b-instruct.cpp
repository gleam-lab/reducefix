#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
set<int> neighbors[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    neighbors[u].insert(v);
    neighbors[v].insert(u);
}

int findKthLargestNeighbor(int u, int k) {
    auto it = neighbors[u].end();
    advance(it, -k);
    if (it == neighbors[u].begin()) {
        return -1;
    }
    return *(--it);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        neighbors[i].insert(-i);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int u, k;
            cin >> u >> k;
            cout << findKthLargestNeighbor(u, k) << "\n";
        }
    }

    return 0;
}