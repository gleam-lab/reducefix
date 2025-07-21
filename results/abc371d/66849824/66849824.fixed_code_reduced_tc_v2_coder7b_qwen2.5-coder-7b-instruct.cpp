#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
ll solve(const vector<int>& X,const vector<int>& P,int L,int R){
    auto it_L=lower_bound(all(X),L);
    auto it_R=upper_bound(all(X),R);
    return accumulate(it_L,it_R,P.begin());
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n;
    vector<int> X(n),P(n);
    rep(i,n){
        cin>>X[i]>>P[i];
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<solve(X,P,L,R)<<'\n';
    }
    return 0;
}