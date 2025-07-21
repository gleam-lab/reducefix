#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
queue<int> q;

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for (ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    
    // Initialize visited array and step count array
    bool vis[MAXN] = {false};
    ll step[MAXN] = {0};
    
    // Use queue to perform BFS starting from node 1
    q.push(1);
    vis[1] = true;
    
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        
        // Check all adjacent nodes
        for (int adj : vec[top]) {
            if (adj == 1) {
                // If the neighbor is node 1 and it's not the source node
                printf("%lld", step[top] + 1);
                return 0;
            }
            // Continue to explore other nodes
            if (!vis[adj]) {
                vis[adj] = true;
                step[adj] = step[top] + 1;
                q.push(adj);
            }
        }
    }
    
    // If no path is found
    printf("-1");
    return 0;
}