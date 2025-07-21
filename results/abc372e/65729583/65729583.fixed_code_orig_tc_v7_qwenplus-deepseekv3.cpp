#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
vector<int> component[MAXN];

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
    
    parent[v] = u;
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    component[v].clear();
    
    sort(component[u].rbegin(), component[u].rend());
    if (component[u].size() > MAXK) {
        component[u].resize(MAXK);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i] = {i};
    }
    
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (k > component[v].size()) {
                cout << "-1\n";
            } else {
                cout << component[v][k-1] << '\n';
            }
        }
    }
    
    return 0;
}