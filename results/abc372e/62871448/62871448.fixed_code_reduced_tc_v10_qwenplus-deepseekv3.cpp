#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 10;

int parent[MAXN];
vector<int> adj[MAXN];
vector<int> top_k[MAXN];

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
        parent[b] = a;
        
        // Merge the adjacency lists
        adj[a].insert(adj[a].end(), adj[b].begin(), adj[b].end());
        adj[b].clear();
        
        // Merge and maintain top 10 elements
        vector<int> merged;
        merge(top_k[a].rbegin(), top_k[a].rend(),
              top_k[b].rbegin(), top_k[b].rend(),
              back_inserter(merged),
              greater<int>());
        if (merged.size() > MAXK)
            merged.resize(MAXK);
        top_k[a] = merged;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        adj[i].push_back(i);
        top_k[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (v > top_k[root].size()) {
                cout << "-1\n";
            } else {
                cout << top_k[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}