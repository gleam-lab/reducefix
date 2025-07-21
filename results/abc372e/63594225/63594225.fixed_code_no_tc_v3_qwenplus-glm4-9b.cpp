#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N 200005

vector<int> adj[N];
vector<int> nodes;

ll findKthLargest(int node, int k) {
    sort(adj[node].rbegin(), adj[node].rend()); // Sort in descending order
    if (k > adj[node].size() || k <= 0) return -1;
    return adj[node][k-1];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    while (q--) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) { // Add edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else { // Find k-th largest
            cout << findKthLargest(v, k) << '\n';
        }
    }

    return 0;
}