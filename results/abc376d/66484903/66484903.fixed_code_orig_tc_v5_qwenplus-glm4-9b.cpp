#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);  // Ensure bidirectional edges for undirected graphs
    }

    for(int i = 0; i <= n; i++){
        step[i] = -1;  // Initialize step to -1
        vis[i] = false;
    }

    q.push(1);
    step[1] = 0;  // Set the distance to the start node to 0
    while(!q.empty()){
        ll top = q.front();
        vis[top] = true;
        q.pop();

        for(ll i = 0; i < vec[top].size(); i++){
            ll to = vec[top][i];
            if(step[to] == -1 && !vis[to]){
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }

    // Check if BFS has explored all nodes
    for(ll i = 1; i <= n; i++){
        if(step[i] == -1 && i != 1){
            printf("-1\n");
            return 0;
        }
    }

    // Print the steps to each node from node 1
    for(ll i = 1; i <= n; i++){
        printf("%lld ", step[i]);
    }
    printf("\n");
    return 0;
}