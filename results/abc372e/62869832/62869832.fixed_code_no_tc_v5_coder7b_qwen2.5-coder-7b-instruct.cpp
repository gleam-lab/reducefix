#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int findKthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    if (arr.size() < k) return -1;
    return arr[arr.size() - k];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; ++i) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            addEdge(u, v);
        } else {
            vector<int> connectedVertices = adj[u];
            cout << findKthLargest(connectedVertices, v) << endl;
        }
    }
    
    return 0;
}