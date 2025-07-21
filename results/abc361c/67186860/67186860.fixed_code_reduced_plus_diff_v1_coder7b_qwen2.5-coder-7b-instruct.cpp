#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  for(int i=0;i<n;++i){
      cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  long long ans = LLONG_MAX;
  for(int i=0;i<=n-k;++i){
      ans=min(ans,arr[i+k-1]-arr[i]);
  }
  cout<<ans<<endl;
  return 0;
}