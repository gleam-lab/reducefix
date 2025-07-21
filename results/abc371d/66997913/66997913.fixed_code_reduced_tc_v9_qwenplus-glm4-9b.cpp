#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end()); // Sort the array for efficient range queries
  
  vector<ll> p(n), s(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i+1] = s[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // Find the indices in the sorted array for the bounds
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    
    // Calculate the prefix sum difference
    ll ans = s[rt] - s[lt];
    cout << ans << endl;
  }
  return 0;
}