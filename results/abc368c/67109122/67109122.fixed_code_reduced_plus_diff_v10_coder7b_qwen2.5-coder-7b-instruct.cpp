#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

ll solve(vector<ll>& v){
    ll n=v.size();
    ll ans=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(ll i=0;i<n;i++){
        if(v[i]>0){
            pq.push({v[i],i});
        }
    }
    while(!pq.empty()){
        auto [val,idx]=pq.top();pq.pop();
        ans+=val;
        val--;
        pq.push({val,idx});
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<solve(v)<<endl;
    return 0;
}