#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int dist[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    int min_cycle = INT_MAX;
    
    for(int start = 1; start <= n; start++) {
        if(adj[start].empty()) continue;
        
        fill(dist, dist + n + 1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v : adj[u]) {
                if(v == start) {
                    min_cycle = min(min_cycle, dist[u] + 1);
                    break;
                }
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if(min_cycle == 3) break; // Early exit if we find the smallest possible cycle
        }
        if(min_cycle == 3) break; // Early exit if we find the smallest possible cycle
    }
    
    cout << (min_cycle == INT_MAX ? -1 : min_cycle) << endl;
    
    return 0;
}