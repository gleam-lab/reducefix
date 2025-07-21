#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int parent[MAXN];
vector<int> adj[MAXN];
set<int, greater<int>> top[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (top[u].size() < top[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    for (int x : top[v]) {
        top[u].insert(x);
        if (top[u].size() > K) {
            top[u].erase(prev(top[u].end()));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        top[i].insert(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            merge(u, v);
        } else {
            int root = find(u);
            if (top[root].size() < v) {
                cout << "-1\n";
            } else {
                auto it = top[root].begin();
                advance(it, v-1);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}