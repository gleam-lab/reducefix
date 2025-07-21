#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> lst[MAXN];
int fa[MAXN];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (lst[u].size() < lst[v].size()) swap(u, v);
    
    // Merge the smaller list into the larger one
    lst[u].insert(lst[u].end(), lst[v].begin(), lst[v].end());
    sort(lst[u].rbegin(), lst[u].rend());
    if (lst[u].size() > 10) lst[u].resize(10);
    
    fa[v] = u;
    lst[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        lst[i] = {i};
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (lst[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << lst[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}