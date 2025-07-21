#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int parent[N];
vector<int> component[N];

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    // Merge smaller component into larger one
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    component[v].clear();
    
    // Keep only top 10 elements to satisfy k <= 10 constraint
    if (component[u].size() > 10) {
        nth_element(component[u].begin(), component[u].begin() + 10, component[u].end(), greater<int>());
        component[u].resize(10);
    }
    
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (q--) {
        int cmd;
        cin >> cmd;
        
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            
            if (component[v].size() < k) {
                cout << -1 << '\n';
            } else {
                // Sort in descending order to get k-th largest
                nth_element(component[v].begin(), component[v].begin() + k - 1, component[v].end(), greater<int>());
                cout << component[v][k - 1] << '\n';
            }
        }
    }
    
    return 0;
}