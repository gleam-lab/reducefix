#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int degree[200005];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
}

void removeEdge(int u, int v) {
    auto it = find(adj[u].begin(), adj[u].end(), v);
    if(it != adj[u].end()) adj[u].erase(it);
    it = find(adj[v].begin(), adj[v].end(), u);
    if(it != adj[v].end()) adj[v].erase(it);
    degree[u]--;
    degree[v]--;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int u, v; cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k; cin >> v >> k;
            if(degree[v] < k) cout << "-1" << endl;
            else {
                vector<int> temp = adj[v];
                sort(temp.begin(), temp.end());
                cout << temp[temp.size()-k] << endl;
            }
        }
    }
    return 0;
}