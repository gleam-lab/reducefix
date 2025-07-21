#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 9;

vector<int> parent(MAXN), rank(MAXN);
vector<set<int>> adjacencyLists[MAXN];

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    u = find(u), v = find(v);
    if (rank[u] < rank[v]) swap(u, v);
    if (rank[u] == rank[v]) ++rank[u];
    parent[v] = u;
    adjacencyLists[u].merge(adjacencyLists[v]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        adjacencyLists[i].insert(i);
    }

    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else {
            int u, k;
            cin >> u >> k;
            u = find(u);
            
            if (adjacencyLists[u].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = adjacencyLists[u].rbegin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}