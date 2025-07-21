#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
vector<int> topk[MAXN];

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
    
    if (topk[u].size() < topk[v].size()) {
        swap(u, v);
    }
    
    vector<int> merged;
    int i = 0, j = 0;
    while (merged.size() < MAXK && (i < topk[u].size() || j < topk[v].size())) {
        if (j >= topk[v].size() || (i < topk[u].size() && topk[u][i] >= topk[v][j])) {
            merged.push_back(topk[u][i++]);
        } else {
            merged.push_back(topk[v][j++]);
        }
    }
    
    topk[u] = merged;
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        topk[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (topk[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << topk[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}