#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
const ll mod=1e9+7;

vector<ll> par,h,rnk;

ll find(ll x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}

bool unite(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y)return false;
    if(rnk[x]>rnk[y]){
        par[y]=x;
        h[x]+=h[y];
    }
    else{
        par[x]=y;
        h[y]+=h[x];
        if(rnk[x]==rnk[y])rnk[y]++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll h,w,q,i,j,x,y;
    cin>>h>>w>>q;

    par.resize(h*w);
    h.resize(h*w);
    rnk.resize(h*w);

    for(i=0;i<h*w;i++){
        par[i]=i;
        h[i]=1;
        rnk[i]=0;
    }

    while(q--){
        cin>>x>>y;
        x--,y--;

        ll id=x*w+y;
        if(find(id)==id){
            h[id]=0;
        }
        else{
            if(h[id]==1){
                unite(id,id-h[id]);
            }
            if(h[id]==-1){
                unite(id,id+h[id]);
            }
        }
    }

    ll ans=0;
    for(i=0;i<h*w;i++){
        if(h[i]!=0){
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}