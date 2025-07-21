#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const int MAX = 400005;
vector<set<pair<int,int>>> row(MAX), col(MAX);

int main() {
    int h, w, q; cin >> h >> w >> q;
    rep(i, h) rep(j, w) {
        row[i].insert({j, i});
        col[j].insert({i, j});
    }
    
    rep(qq, q) {
        int r, c; cin >> r >> c; r--, c--;
        
        auto it_r = row[r].lower_bound({c, -1});
        auto it_c = col[c].lower_bound({r, -1});
        
        if(it_r != row[r].end() && it_r->first == c) {
            row[r].erase(it_r);
            col[it_r->second].erase({r, c});
        } else {
            pair<int, int> up = {INT_MAX, INT_MAX}, dn = {-1, -1}, lf = {-1, -1}, rt = {-1, -1};
            
            if(it_r != row[r].begin()) {
                --it_r;
                up = *it_r;
                ++it_r;
            }
            
            if(it_r != row[r].end()) {
                rt = *it_r;
            }
            
            if(it_c != col[c].begin()) {
                --it_c;
                lf = *it_c;
                ++it_c;
            }
            
            if(it_c != col[c].end()) {
                dn = *it_c;
            }
            
            if(up.first != INT_MAX) {
                row[up.second].erase(up);
                col[up.first].erase(up);
            }
            
            if(dn.first != -1) {
                row[dn.second].erase(dn);
                col[dn.first].erase(dn);
            }
            
            if(lf.first != -1) {
                row[lf.second].erase(lf);
                col[lf.first].erase(lf);
            }
            
            if(rt.first != -1) {
                row[rt.second].erase(rt);
                col[rt.first].erase(rt);
            }
        }
    }
    
    int ans = 0;
    rep(i, h) ans += row[i].size();
    cout << ans << endl;
    
    return 0;
}