#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(int node, int k) {
    vector<int> neighbors = adj[node];
    sort(neighbors.begin(), neighbors.end());
    if (neighbors.size() < k) return -1;
    return neighbors[k-1];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= q; ++i) {
        int type, u, v, k;
        cin >> type;
        
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            cin >> u >> k;
            cout << findKthLargest(u, k) << endl;
        }
    }
    
    return 0;
}