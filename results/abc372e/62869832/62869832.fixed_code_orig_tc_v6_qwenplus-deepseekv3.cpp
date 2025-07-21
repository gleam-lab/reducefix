#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> sets[MAXN];

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
    
    if (sets[u].size() < sets[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    sets[u].insert(sets[u].end(), sets[v].begin(), sets[v].end());
    sets[v].clear();
    
    sort(sets[u].rbegin(), sets[u].rend());
    if (sets[u].size() > 10) {
        sets[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sets[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > sets[root].size()) {
                cout << "-1\n";
            } else {
                cout << sets[root][v-1] << "\n";
            }
        }
    }
    
    return 0;
}