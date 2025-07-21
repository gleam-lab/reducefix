#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define rep(i,n) for(int i=0;i<(int)n;i++)
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



// ll inf=(1ll<<61);
// int inf=(1<<30);


// ll rui(ll a,ll b){
//     if(b==0)return 1;
//     if(b%2==1) return a*rui(a*a,b/2);
//     return rui(a*a,b/2);
// }

// ll const mod=998244353;
// ll modrui(ll a,ll b){
//     if(b==0)return 1;
//     if(b%2==1) return a%mod*modrui(a%mod*a%mod,b/2)%mod;
//     return modrui(a%mod*a%mod,b/2)%mod;
// }

// ll inv(ll x){
//     return modrui(x,mod-2);
// }





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
            // printf("{%lld,%lld} ",r+1,c+1);
            // cout << endl;
        }
        else{
            er.assign(4,vl(2,-1));
            if(row[r].upper_bound(c)!=row[r].end()){er[0][1]=*row[r].upper_bound(c);er[0][0]=r;}
            if(!row[r].empty()){er[2][1]=*(--row[r].upper_bound(c));er[2][0]=r;}
            if(col[c].upper_bound(r)!=col[c].end()){er[1][0]=*col[c].upper_bound(r);er[1][1]=c;}
            if(!col[c].empty()){er[3][0]=*(--col[c].upper_bound(r));er[3][1]=c;}
            
            // rep(k,4)printf("{%lld,%lld} ",er[k][0]+1,er[k][1]+1);
            // cout << endl;

            rep(k,4){
                if(er[k][0]!=-1 && er[k][1]!=-1){
                    row[er[k][0]].erase(er[k][1]);
                    col[er[k][1]].erase(er[k][0]);
                }
            }
        }
    }
    ll ans=0;
    rep(i,h){
        ans+=row[i].size();
    }
    cout << ans << endl;
}