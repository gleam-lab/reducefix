#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
const int MAX_K = 10;

int parent[MAX_N];
vector<int> topk[MAX_N];

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
    while ((i < topk[u].size() || j < topk[v].size()) && merged.size() < MAX_K) {
        if (i < topk[u].size() && (j >= topk[v].size() || topk[u][i] >= topk[v][j])) {
            merged.push_back(topk[u][i]);
            i++;
        } else {
            merged.push_back(topk[v][j]);
            j++;
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
        topk[i] = {i};
    }
    
    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > (int)topk[root].size()) {
                cout << "-1\n";
            } else {
                cout << topk[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}