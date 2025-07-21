#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> parent(MAX_N), rank(MAX_N);
map<int, priority_queue<int>> pq;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
    
    pq[v].merge(pq[u]);
    pq.erase(u);
}

int getKthLargest(int v, int k) {
    v = find(v);
    auto it = pq.find(v);
    if (it == pq.end() || it->second.size() < k) return -1;
    auto kth_largest = it->second;
    while (--k) kth_largest.pop();
    return kth_largest.top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
        pq[i].push(i);
    }
    
    for (int i = 0; i < q; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            cout << getKthLargest(v, k) << '\n';
        }
    }
    
    return 0;
}