#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> pieces(m);
    for(ll i=0; i<m; ++i){
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<ll,ll>> occupied;
    for(auto& [x,y]: pieces){
        occupied.insert({x,y});
    }
    
    set<ll> sum_set, diff_set;
    for(auto& [x,y]: pieces){
        sum_set.insert(x+y);
        diff_set.insert(x-y);
    }
    
    ll ans = n*n - m;
    
    for(auto& [x,y]: pieces){
        if(!occupied.count({x+1,y}) && !sum_set.count(x+y+1)) ans++;
        if(!occupied.count({x-1,y}) && !sum_set.count(x+y-1)) ans++;
        if(!occupied.count({x,y+1}) && !diff_set.count(x-y-1)) ans++;
        if(!occupied.count({x,y-1}) && !diff_set.count(x-y+1)) ans++;
    }
    
    cout << ans << '\n';
    
    return 0;
}