#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int, ll>> villages(n);
  for (int i = 0; i < n; i++) {
    cin >> villages[i].first;
    cin >> villages[i].second;
  }
  
  sort(villages.begin(), villages.end());
  
  vector<ll> prefix_sum(n + 1);
  for (int i = 0; i < n; i++) {
    prefix_sum[i + 1] = prefix_sum[i] + villages[i].second;
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    
    auto lb = lower_bound(villages.begin(), villages.end(), make_pair(l, 0));
    auto ub = upper_bound(villages.begin(), villages.end(), make_pair(r, INT_MAX));
    
    if (lb == villages.end() || (*lb).first > r) {
      --ub;
    }
    
    ll result = prefix_sum[ub->second] - prefix_sum[lb->second];
    cout << result << endl;
  }
  
  return 0;
}