#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    vector<ll> s(n+1);
    rep(i,n)cin>>a[i];
    rep(i,n)s[i+1]=s[i]+a[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
}