#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for(int i=0;i<n;++i){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  long long ans=v[n-k]-v[k-1];
  cout<<ans<<endl;
  return 0;
}