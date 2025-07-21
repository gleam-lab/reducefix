#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,a[1005],b[1005],ans;
unordered_set<ll> s,t,u,v;
map<pair<ll,ll>,bool> vis;

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%lld%lld",&a[i],&b[i]);
        s.insert(a[i]);
        t.insert(b[i]);
        u.insert(a[i]-b[i]);
        v.insert(a[i]+b[i]);
    }
    ans=(n-s.size())*(n-t.size());
    for(auto x:u){
        ll tmp=n-abs(x);
        for(auto y:s){
            if(y-x>=1&&y-x<=n&&!vis[{y,y-x}]){
                --tmp;
                vis[{y,y-x}]=1;
            }
        }
        for(auto y:t){
            if(x+y>=1&&x+y<=n&&!vis[{x+y,y}]){
                --tmp;
                vis[{x+y,y}]=1;
            }
        }
        ans-=tmp;
    }
    for(auto x:v){
        ll tmp=n-abs(x-n);
        for(auto y:s){
            if(x-y>=1&&x-y<=n&&!vis[{y,x-y}]){
                --tmp;
                vis[{y,x-y}]=1;
            }
        }
        for(auto y:t){
            if(x-y>=1&&x-y<=n&&!vis[{x-y,y}]){
                --tmp;
                vis[{x-y,y}]=1;
            }
        }
        for(auto y:u){
            ll p=x+y,q=x-y;
            if(p%2==0&&p/2>=1&&p/2<=n&&q/2>=1&&q/2<=n&&!vis[{p/2,q/2}]){
                --tmp;
                vis[{p/2,q/2}]=1;
            }
        }
        ans-=tmp;
    }
    printf("%lld\n",ans+1);
    return 0;
}