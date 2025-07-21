#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repi(i,a,b) for(int i=a;i<(int)b;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main() {
    ll h,w,q; cin >> h >> w >> q;
    vector<vl> er;
    vector<set<ll>> row(h), col(w);
    
    rep(i,h) rep(j,w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    
    rep(i,q) {
        ll r,c; cin >> r >> c;
        r--, c--;
        
        if(row[r].find(c) != row[r].end()) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            er.assign(4, vl(2, -1));
            
            auto it = row[r].upper_bound(c);
            if(it != row[r].end()) er[0] = {r, *it};
            if(it != row[r].begin()) {
                it--;
                er[2] = {r, *it};
                it++;
            }
            
            it = col[c].upper_bound(r);
            if(it != col[c].end()) er[1] = {*it, c};
            if(it != col[c].begin()) {
                it--;
                er[3] = {*it, c};
                it++;
            }
            
            rep(k, 4) {
                if(er[k][0] != -1 && er[k][1] != -1) {
                    row[er[k][0]].erase(er[k][1]);
                    col[er[k][1]].erase(er[k][0]);
                }
            }
        }
    }
    
    ll ans = 0;
    rep(i,h) ans += row[i].size();
    cout << ans << endl;
}