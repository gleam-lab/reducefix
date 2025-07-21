#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,n) for(int i=0;i<=n;++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb(a) push_back(a)
#define yes() puts("Yes")
#define no() puts("No")

int main(){
    int n,q; cin>>n>>q;
    vector<int> x(n),p(n+1);
    rep(i,n)cin>>x[i];
    rep(i,n)cin>>p[i+1];
    partial_sum(all(p),all(p));
    while(q--){
        int l,r; cin>>l>>r;
        int posl=lower_bound(all(x),l)-x.begin();
        int posr=upper_bound(all(x),r)-x.begin();
        if(posl==n)posl--;
        if(posr==0)posr++;
        cout<<p[posr]-p[posl+1]<<endl;
    }
}