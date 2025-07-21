#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 10;

vector<int> adj[MAXN];
int parent[MAXN];
int rank_[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void union_set(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (rank_[u] > rank_[v]) {
        parent[v] = u;
    } else if (rank_[u] < rank_[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        rank_[u]++;
    }
}

void merge_adj_lists(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    vector<int> merged;
    merge(adj[u].begin(), adj[u].end(), 
          adj[v].begin(), adj[v].end(), 
          back_inserter(merged), greater<int>());
    
    adj[u].clear();
    adj[u] = merged;
    if (adj[u].size() > MAXK) {
        adj[u].resize(MAXK);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        rank_[i] = 0;
        adj[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            if (find(u) != find(v)) {
                merge_adj_lists(u, v);
                union_set(u, v);
            }
        } else {
            int root = find(u);
            if (v > adj[root].size()) {
                cout << "-1\n";
            } else {
                cout << adj[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}