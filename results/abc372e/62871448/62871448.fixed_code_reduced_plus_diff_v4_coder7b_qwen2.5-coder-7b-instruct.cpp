#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 11;

struct UF {
    vector<int> parent, rank;
    UF(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
};

vector<int> adj[MAXN];

void addEdge(UF &uf, int u, int v) {
    uf.unite(u, v);
    adj[uf.find(u)].push_back(v);
    adj[uf.find(v)].push_back(u);
}

priority_queue<int> getNeighbors(int u, const vector<vector<int>>& adj) {
    priority_queue<int> pq;
    for (int v : adj[u]) {
        pq.push(v);
    }
    return pq;
}

int kthLargest(const priority_queue<int>& pq, int k) {
    while (!pq.empty() && --k >= 1) {
        pq.pop();
    }
    return pq.empty() ? -1 : pq.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    UF uf(n + 1);
    vector<priority_queue<int>> pq(n + 1);
    
    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op;
        
        if (op == 1) {
            cin >> u >> v;
            addEdge(uf, u, v);
        } else {
            cin >> u >> k;
            int root = uf.find(u);
            if (adj[root].size() < k) {
                cout << "-1\n";
            } else {
                cout << kthLargest(pq[root], k) << "\n";
            }
        }
    }
    
    return 0;
}