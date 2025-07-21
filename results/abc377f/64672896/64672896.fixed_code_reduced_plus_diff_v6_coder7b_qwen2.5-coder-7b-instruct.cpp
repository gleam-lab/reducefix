#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(int n, vector<vector<ll>>& pos) {
    set<ll> r, c, d1, d2;
    for(auto& p : pos){
        r.insert(p[0]);
        c.insert(p[1]);
        d1.insert(p[0]+p[1]);
        d2.insert(p[0]-p[1]);
    }
    return n*n-1-((r.size()-1)+(c.size()-1)+(d1.size()-1)+(d2.size()-1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> pos(m,vector<ll>(2));
    for(ll i=0;i<m;++i) cin >> pos[i][0] >> pos[i][1];
    cout << solve(n,pos) << endl;
    return 0;
}