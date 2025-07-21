#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), prefix(n+1, 0);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    prefix[i+1] = prefix[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // Find first element >= l
    auto left_it = lower_bound(x.begin(), x.end(), l);
    int left_idx = left_it - x.begin();
    
    // Find first element > r
    auto right_it = upper_bound(x.begin(), x.end(), r);
    int right_idx = right_it - x.begin();
    
    // Sum from left_idx to right_idx-1 in p array
    ll ans = prefix[right_idx] - prefix[left_idx];
    cout << ans << endl;
  }
  return 0;
}