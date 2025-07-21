#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define trav(a,x) for(auto&a:x)
const int MOD=1e9+7;
const int INF=1e9+7;
void solve(){
    ll n;cin>>n;
    vector<ll> h(n);
    rep(i,0,n)cin>>h[i];
    ll t=0;
    while(1){
        bool flag=false;
        rep(i,0,n){
            if(h[i]>0){
                if((t+1)%3==0)h[i]-=3;
                else h[i]--;
                t++;
                if(h[i]<0)flag=true;
            }
        }
        if(!flag)break;
    }
    cout<<t<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}