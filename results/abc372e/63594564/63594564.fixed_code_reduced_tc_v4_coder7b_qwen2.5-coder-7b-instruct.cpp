#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>

const int N = 2e5 + 5;

vi adj[N];
priority_queue<int,vector<int>,greater<int>> pq[N];

void addEdge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
    pq[u].push(v);
    pq[v].push(u);
    if(pq[u].size()>10)pq[u].pop();
    if(pq[v].size()>10)pq[v].pop();
}

int findKthLargest(int u, int k){
    if(k>pq[u].size())return -1;
    auto it = pq[u];
    int res;
    while(k--){
        res = it.top();it.pop();
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;cin>>n>>q;
    while(q--){
        int type,u,v,k;
        cin>>type;
        if(type==1){
            cin>>u>>v;
            addEdge(u,v);
        }else{
            cin>>u>>k;
            cout<<findKthLargest(u,k)<<'\n';
        }
    }
    return 0;
}