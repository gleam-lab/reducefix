#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 10;

int parent[MAXN];
vector<int> topk[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v)
        return;
    
    if (topk[u].size() < topk[v].size())
        swap(u, v);
    
    vector<int> merged;
    merge(topk[u].rbegin(), topk[u].rend(),
          topk[v].rbegin(), topk[v].rend(),
          back_inserter(merged), greater<int>());
    
    topk[u].clear();
    for (int i = 0; i < min((int)merged.size(), MAXK); ++i)
        topk[u].push_back(merged[i]);
    
    parent[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topk[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (v > (int)topk[root].size()) {
                cout << "-1\n";
            } else {
                cout << topk[root][v - 1] << "\n";
            }
        }
    }
    
    return 0;
}