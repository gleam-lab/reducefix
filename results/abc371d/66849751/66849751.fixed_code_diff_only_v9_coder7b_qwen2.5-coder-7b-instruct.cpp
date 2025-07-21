#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=0;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout<<((b)?"Yes":"No")<<endl
#define YES(b) cout<<((b)?"YES":"NO")<<endl
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){int n,m,i,j,k,l,r,x,y,z,a,b,c,d,e,f,g,h,t,p,q,o,w,u,v,s,tot=0,sum=0,ans=0,inf=1e9;
    cin>>n;
    vector<int> v(n+1),p(n+1),a(n);
    p[0]=0;
    rep(i,n){cin>>a[i];v[i]=a[i];}
    sort(all(v));
    rep(i,n){p[i+1]=p[i]+v[i];}
    map<int,int> mp;
    rep(i,n){mp[v[i]]=i;}
    cin>>q;
    rep(i,q){
        int l,r;
        cin>>l>>r;
        auto it1=lower_bound(all(v),l);
        auto it2=upper_bound(all(v),r);
        int idx1=it1-v.begin();
        int idx2=it2-v.begin();
        if(idx2==n)idx2--;
        ans=p[idx2+1]-p[idx1];
        cout<<ans<<endl;
    }
    return 0;
}