#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(vector<int>& vec, int k) {
    sort(vec.begin(), vec.end());
    if(k > vec.size()) return -1;
    else return vec[k-1];
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    
    while(q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if(op == 1) {
            addEdge(u, v);
        } else {
            vector<int> neighbors;
            for(auto neighbor : adj[v]) {
                neighbors.push_back(neighbor);
            }
            cout << findKthLargest(neighbors, v) << endl;
        }
    }
    
    return 0;
}