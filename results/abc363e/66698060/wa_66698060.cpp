#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)



// ll inf=(1ll<<62);

// ll rui(ll a,ll b){
//     if(b==0)return 1;
//     if(b%2==1) return a*rui(a*a,b/2);
//     return rui(a*a,b/2);
// }


ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
    ll h,w,y,ans;cin >> h >> w >> y;
    ans=h*w;
    vector room(h,vl(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    priority_queue<vl,vector<vl>,greater<vl>> pq;
    vector used(h,vb(w,0));
    rep(i,h){
        pq.push({room[i][0],i,0});
        used[i][0]=1;
        pq.push({room[i][w-1],i,w-1});
        used[i][w-1]=1;
    }
    for(ll j=1;j<w-1;j++){
        pq.push({room[0][j],0,j});
        used[0][j]=1;
        pq.push({room[h-1][j],h-1,j});
        used[h-1][j]=1;
    }
    ll now=0;
    while(now++<y){
        // cout << now << endl;
        while(true){
            if(pq.empty() || pq.top()[0]>now)break;
            // cout << "a";
            ll ni=pq.top()[1],nj=pq.top()[2];
            // cout << "b";
            pq.pop();ans--;
            // cout << "c";
            rep(k,4){
                ll nexi=ni+dx[k],nexj=nj+dy[k];
                // cout << "d";
                if(0<=nexi && nexi<h && 0<=nexj && nexj<w && !used[nexi][nexj]){
                    pq.push({room[nexi][nexj],nexi,nexj});
                    used[nexi][nexj]=1;
                }
            }
            // cout << "e";
        }
        cout << ans << endl;
    }
}