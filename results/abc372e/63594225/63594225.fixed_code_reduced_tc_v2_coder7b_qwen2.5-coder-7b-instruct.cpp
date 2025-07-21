#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>

const int MAXN = 2e5 + 5;

vi adj[MAXN];
priority_queue<int,vector<int>,greater<int>> pq[MAXN];

void addEdge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void query(int v, int k){
    while(!pq[v].empty()){
        pq[v].pop();
    }
    for(auto it:adj[v]){
        pq[it].push(it);
    }
    if(k>pq[v].size()) cout<<-1<<endl;
    else{
        for(int i=0;i<k-1;i++){
            pq[v].pop();
        }
        cout<<pq[v].top()<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    while(q--){
        int type,u,v,k;
        cin>>type;
        if(type==1){
            cin>>u>>v;
            addEdge(u,v);
        }
        else{
            cin>>u>>k;
            query(u,k);
        }
    }
    return 0;
}