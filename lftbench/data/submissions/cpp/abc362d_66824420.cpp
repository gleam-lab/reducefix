#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	vector<vector<pair<int,int>>>adj(n+1);
	for(int j=0;j<m;j++){
	    int x,y,w;
	    cin>>x>>y>>w;
	    adj[x].push_back({y,w});
	    adj[y].push_back({x,w});
	}
	
	vector<long long>dist(n+1,1E10+0);
	dist[1]=a[0];
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
	q.push({a[0],1});
	while(q.size()){
	    pair<long long,long long>p=q.top();
	    q.pop();
	    long long val=p.first,node=p.second;
	    for(auto it:adj[node]){
	        long long total_dist=val+it.second+a[it.first-1];
	        if(total_dist<dist[it.first]){
	            dist[it.first]=total_dist;
	            q.push({total_dist,it.first});
	        }
	    }
	    
	}
	
	for(int i=2;i<=n;i++){
	    cout<<dist[i]<<" ";
	}
	
	
	
	
}
