#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
vector<int> adj[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int parent, vector<int>& dist, int level = 0) {
    dist[node] = level;
    for(auto child : adj[node]) {
        if(child != parent) {
            dfs(child, node, dist);
        }
    }
}

int kthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    return arr[k-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    vector<int> dist(n+1, 0);
    dfs(1, -1, dist);

    while(q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) {
            // Edge addition handled during initialization
        } else {
            if(k > dist[v]) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                for(auto neighbor : adj[v]) {
                    temp.push_back(dist[neighbor]);
                }
                cout << kthLargest(temp, k) << "\n";
            }
        }
    }

    return 0;
}