#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
int degree[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}

int findKthLargest(int v, int k) {
    vector<int> neighbors;
    for (int neighbor : adj[v]) {
        neighbors.push_back(neighbor);
    }
    
    sort(neighbors.begin(), neighbors.end());
    if (k > neighbors.size()) return -1;
    return neighbors[k-1];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    while (Q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            cin >> v >> k;
            cout << findKthLargest(v, k) << endl;
        }
    }
    return 0;
}