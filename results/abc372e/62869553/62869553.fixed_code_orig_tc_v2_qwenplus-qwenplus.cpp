#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
set<int> component[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    
    // Always merge smaller set into larger set
    if (component[x].size() < component[y].size())
        swap(x, y);
    
    for (int val : component[y]) {
        component[x].insert(val);
        parent[val] = x;
    }
    component[y].clear();
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
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (component[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].rbegin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}