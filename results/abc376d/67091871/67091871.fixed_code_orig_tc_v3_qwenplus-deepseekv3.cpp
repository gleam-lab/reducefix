#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int dist[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    queue<int> q;
    q.push(1);
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    
    int min_cycle = MAXN;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(v == 1) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if(min_cycle == MAXN) {
        cout << -1 << endl;
    } else {
        cout << min_cycle << endl;
    }
    
    return 0;
}