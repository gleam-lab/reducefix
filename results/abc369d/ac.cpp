#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
int main(){
  int N; cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];
  ll dp0=0,dp1=-1e18;
  for(int i=0;i<N;i++){
    ll even=dp1,odd=dp0;
    dp0=max(dp0,even+2*A[i]);
    dp1=max(dp1,odd+A[i]);
  }
  cout<<max(dp0,dp1)<<endl;
}