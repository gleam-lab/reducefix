#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end()); // Sort the array to use binary search effectively
  
  vector<ll> p(n), s(n+1);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i+1] = s[i]+p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(x.begin(), x.end(), l); // Find first element not less than l
    auto itr = upper_bound(x.begin(), x.end(), r); // Find first element greater than r
    
    int idxl = itl - x.begin(); // Index of the first element not less than l
    int idxr = itr - x.begin(); // Index of the first element greater than r
    
    if (idxl >= n || idxr <= 0) { // Check for out-of-bounds indices
      cout << 0 << endl; // No elements in range [l, r]
      continue;
    }
    
    int ans = s[idxr] - s[idxl]; // Calculate sum using prefix sums
    cout << ans << endl;
  }
  return 0;
}