#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    
    set<pair<ll,ll>> st;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        st.insert({x,y});
    }
    
    ll ans=n*n;
    unordered_set<ll> rows,cols,d1,d2;
    
    for(auto [x,y]:st){
        rows.insert(x);
        cols.insert(y);
        d1.insert(x+y);
        d2.insert(x-y);
    }
    
    for(auto &x:rows) ans-=n;
    for(auto &y:cols) ans-=n;
    for(auto &s:d1) ans-=n;
    for(auto &s:d2) ans-=n;
    
    for(auto [x,y]:st){
        if(rows.find(x)!=rows.end()) ans++;
        if(cols.find(y)!=cols.end()) ans++;
        if(d1.find(x+y)!=d1.end()) ans++;
        if(d2.find(x-y)!=d2.end()) ans++;
    }
    
    cout<<ans<<"\n";
    
    return 0;
}