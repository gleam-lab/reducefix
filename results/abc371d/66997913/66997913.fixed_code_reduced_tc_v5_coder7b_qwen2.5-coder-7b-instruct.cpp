#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i+1] = s[i] + p[i];
  }

  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    
    // Find the index of the first element greater than r
    auto it_r = upper_bound(x.begin(), x.end(), r);
    if(it_r == x.begin()) continue; // If no such element exists, skip this query
    
    // Find the index of the first element greater than or equal to l
    auto it_l = lower_bound(x.begin(), x.end(), l);

    // Calculate the sum of villagers in the range [l, r]
    int rt = it_r - x.begin() - 1;
    int lt = it_l - x.begin();
    ll ans = s[rt+1] - s[lt];
    cout << ans << endl;
  }
  return 0;
}