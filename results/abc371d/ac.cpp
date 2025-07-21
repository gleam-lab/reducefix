#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  vector<long long> vec(n);
  for(long long i = 0; i < n; i++){
    long long a;
    cin >> a;
    v[i].first = a;
    vec[i] = a;
  }
  for(long long i = 0; i < n; i++){
    long long a;
    cin >> a;
    v[i].second = a;
  }
  sort(v.begin(), v.end());
  sort(vec.begin(), vec.end());
  
  vector<long long> fromLeft(n + 1);
  for(long long i = 0; i < n; i++){
    fromLeft[i + 1] = fromLeft[i] + v[i].second;
  }
  
  long long q;
  cin >> q;
  for(long long i = 0; i < q; i++){
    long long a, b;
    cin >> a >> b;
    
    auto itr1 = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
    auto itr2 = upper_bound(vec.begin(), vec.end(), b) - vec.begin();
    long long ans = fromLeft[itr2] - fromLeft[itr1];
    cout << ans << '\n';
  }
 
  return 0;
}