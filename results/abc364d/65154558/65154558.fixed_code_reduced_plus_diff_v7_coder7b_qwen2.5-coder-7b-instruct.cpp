#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define ROF(i,a,b) for(long long i=b;i>=a;i--)
#define rep(i,n) FOR(i,1,n)
#define trav(a,x) for(auto&a:x)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<string> vs;

ll n,q,k,b,x,y,ans,l,r,mid;
vi a,dist;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    dist.resize(n+1);
    rep(i,n){
        cin>>a[i];
        dist[a[i]]++;
    }
    sort(all(dist));
    FOR(i,1,n){
        dist[i]+=dist[i-1];
    }
    rep(i,q){
        cin>>b>>k;
        l=1,r=n;
        while(l<r){
            mid=(l+r)/2;
            if(dist[mid]<k)r=mid;
            else l=mid+1;
        }
        ans=a[l-1]-b;
        cout<<abs(ans)<<endl;
    }
    return 0;
}