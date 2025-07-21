#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_LIMIT = 10;

int fa[MAXN];
set<int, greater<int>> group[MAXN]; // Store top 10 elements in descending order

// Find with path compression
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// Merge two sets, maintaining only the top K_LIMIT elements
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)
        return;
    
    // Always merge smaller set into larger one
    if (group[fx].size() < group[fy].size())
        swap(fx, fy);
    
    // Merge the elements of fy into fx
    for (auto it = group[fy].begin(); it != group[fy].end(); ++it) {
        group[fx].insert(*it);
        if (group[fx].size() > K_LIMIT)
            group[fx].erase(prev(group[fx].end()));
    }
    
    // Clear fy's set and update parent
    group[fy].clear();
    fa[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    // Initialize DSU and group sets
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        group[i].insert(i);
    }
    
    while (Q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int fv = find(v);
            
            if (group[fv].size() < (size_t)k) {
                cout << -1 << '\n';
            } else {
                auto it = group[fv].begin();
                advance(it, k-1);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}