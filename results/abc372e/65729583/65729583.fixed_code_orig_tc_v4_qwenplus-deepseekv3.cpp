#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int K = 10; // maximum k we need to support

int parent[N];
vector<int> component[N];

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
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    // Merge the smaller component into the larger one
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    component[v].clear();
    
    // Keep only top K elements to optimize space
    if (component[u].size() > 2 * K) {
        nth_element(component[u].begin(), component[u].begin() + K, component[u].end(), greater<int>());
        component[u].resize(K);
    }
    
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (component[v].size() < k) {
                cout << -1 << '\n';
            } else {
                // We need the k-th largest, so we sort in descending order
                nth_element(component[v].begin(), component[v].begin() + k - 1, component[v].end(), greater<int>());
                cout << component[v][k-1] << '\n';
            }
        }
    }
    
    return 0;
}