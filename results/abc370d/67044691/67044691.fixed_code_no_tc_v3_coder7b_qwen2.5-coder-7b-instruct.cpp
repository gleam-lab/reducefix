#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep(i,r) for(ll i=0;i<(ll)r;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
    ll h,w,q;cin >> h >> w >> q;
    vector<vl> er;
    vector<set<ll>> row(h),col(w);
    rep(i,h)rep(j,w){
        row[i].insert(j);
        col[j].insert(i);
    }
    rep(iii,q){
        ll r,c;cin >> r >> c;
        r--;c--;
        if(row[r].find(c)!=row[r].end()){
            row[r].erase(c);
            col[c].erase(r);
        }
        else{
            set<ll>::iterator it;
            it = row[r].lower_bound(c);
            if(it != row[r].end()) {
                row[r].erase(it);
                col[*it].erase(r);
            }
            it = row[r].upper_bound(c);
            if(it != row[r].begin()) {
                it--;
                row[r].erase(it);
                col[*it].erase(r);
            }
            it = col[c].lower_bound(r);
            if(it != col[c].end()) {
                col[c].erase(it);
                row[*it].erase(c);
            }
            it = col[c].upper_bound(r);
            if(it != col[c].begin()) {
                it--;
                col[c].erase(it);
                row[*it].erase(c);
            }
        }
    }
    ll ans=0;
    rep(i,h){
        ans+=row[i].size();
    }
    cout << ans << endl;
}