#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int parent[MAXN];
multiset<int> component[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;
    
    // Always merge smaller set into larger set for efficiency
    if (component[pu].size() < component[pv].size()) {
        swap(pu, pv);
    }
    
    // Merge pv into pu
    for (int x : component[pv]) {
        component[pu].insert(x);
    }
    component[pv].clear();
    parent[pv] = pu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (component[root].size() < (size_t)k) {
                cout << -1 << "\n";
            } else {
                // Get the k-th largest element
                auto it = component[root].rbegin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}