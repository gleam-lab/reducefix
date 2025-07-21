#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 11;

int parent[MAXN];
vector<int> adj[MAXN];  // Stores top 10 largest elements for each set

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (adj[a].size() < adj[b].size())
            swap(a, b);
        
        // Merge b into a
        for (int x : adj[b]) {
            adj[a].push_back(x);
        }
        sort(adj[a].rbegin(), adj[a].rend());
        if (adj[a].size() > MAXK-1)
            adj[a].resize(MAXK-1);
        
        parent[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        adj[i].clear();
        adj[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (adj[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << adj[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}