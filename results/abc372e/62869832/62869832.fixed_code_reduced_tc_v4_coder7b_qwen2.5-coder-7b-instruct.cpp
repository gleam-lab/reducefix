#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> parent(MAXN), size(MAXN), adj[MAXN];
vector<int> sortedVertices(MAXN);

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);
    for (int i = 0; i <= n; ++i) {
        sortedVertices[i].clear();
        sortedVertices[i].push_back(i);
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (size[u] > size[v]) swap(u, v);
    parent[u] = v;
    size[v] += size[u];
    
    // Merge sorted lists
    vector<int>& su = sortedVertices[u];
    vector<int>& sv = sortedVertices[v];
    su.insert(su.end(), sv.begin(), sv.end());
    sort(su.begin(), su.end());
    su.resize(unique(su.begin(), su.end()) - su.begin());
    
    // Update sortedVertices
    sortedVertices[v] = move(su);
}

int kthLargest(vector<int>& sortedList, int k) {
    if (sortedList.size() < k) return -1;
    return sortedList[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    init(n);
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            cout << kthLargest(sortedVertices[root], v) << '\n';
        }
    }
    
    return 0;
}