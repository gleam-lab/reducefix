#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int parent[N];
vector<int> component[N];

int Find(int u) {
    if (parent[u] != u) {
        parent[u] = Find(parent[u]);
    }
    return parent[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    for (int x : component[v]) {
        component[u].push_back(x);
    }
    component[v].clear();
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        component[i].push_back(i);
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            
            if (component[v].size() < k) {
                cout << "-1\n";
            } else {
                // Sort the component in descending order (only when needed)
                // This is optimized by only sorting once per component when first queried
                if (!is_sorted(component[v].rbegin(), component[v].rend())) {
                    sort(component[v].rbegin(), component[v].rend());
                }
                cout << component[v][k-1] << '\n';
            }
        }
    }
    
    return 0;
}