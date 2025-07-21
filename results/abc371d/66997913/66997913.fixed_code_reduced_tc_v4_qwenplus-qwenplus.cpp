#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), prefix_sums(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    prefix_sums[i+1] = prefix_sums[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    
    // Find rightmost position where x[i] <= r
    int right_idx = upper_bound(x.begin(), x.end(), r) - x.begin();
    
    // Find leftmost position where x[i] >= l
    int left_idx = lower_bound(x.begin(), x.end(), l) - x.begin();
    
    ll ans = prefix_sums[right_idx] - prefix_sums[left_idx];
    cout << ans << endl;
  }
  
  return 0;
}