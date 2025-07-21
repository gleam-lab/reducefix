#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
};

const int MAX_N = 2e5 + 10;
vector<int> adj[MAX_N];
priority_queue<int, vector<int>, greater<int>> pq[MAX_N];
int parent[MAX_N];

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (pq[px].size() < pq[py].size()) swap(px, py);
    for (auto &v : pq[py]) pq[px].push(v);
    parent[py] = px;
}

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void process_queries(vector<Edge> &edges, int n, int m) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        pq[i].push(i);
    }
    for (auto &e : edges) {
        union_sets(e.u, e.v);
    }
    for (int i = 1; i <= n; ++i) {
        sort(pq[i].begin(), pq[i].end());
        while (pq[i].size() > 10) pq[i].pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        --edges[i].u;
        --edges[i].v;
    }
    
    process_queries(edges, n, m);
    
    int q;
    cin >> q;
    while (q--) {
        int type, v, k;
        cin >> type >> v >> k;
        --v;
        if (type == 1) {
            int pu = find(v);
            pq[pu].push(v);
            while (pq[pu].size() > 10) pq[pu].pop();
        } else {
            int pv = find(v);
            if (pq[pv].size() < k) {
                cout << "-1\n";
            } else {
                cout << pq[pv].top() + 1 << "\n";
                pq[pv].pop();
                pq[pv].push(v);
                while (pq[pv].size() > 10) pq[pv].pop();
            }
        }
    }
    
    return 0;
}