#include <bits/stdc++.h>
using namespace std;
const int maxN=2e5+5;
int t,n,k,a[maxN],b[maxN];
pair<int,int> p[maxN];
bool cmp(pair<int,int>p1,pair<int,int>p2){
  if(p1.first!=p2.first) return p1.first<p2.first;
  return p1.second<p2.second;
}
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>t;
    while(t--){
      cin>>n>>k;
      vector<pair<int,int>> v(n);
      long long sum=0,ans;
      for(int i=0;i<n;i++) cin>>v[i].first;
      for(int i=0;i<n;i++) cin>>v[i].second;
      sort(v.begin(),v.end(),cmp);
      for(int i=0;i<k;i++){
        sum+=v[i].second;
      }
      ans=v[k-1].first*sum;
      for(int i=k;i<n;i++){
        if(v[i].second<v[v.size()-k].second){
          sum-=v[v.size()-k].second;
          sum+=v[i].second;
        }
        ans=min(ans,sum*v[i].first);
      }
      cout<<ans<<"\n";
    }
    return 0;
}