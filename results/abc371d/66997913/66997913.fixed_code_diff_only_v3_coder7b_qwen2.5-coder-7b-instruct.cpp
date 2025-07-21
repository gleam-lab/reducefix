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
  while(q--) { // Use a loop instead of for loop for better readability
    int l, r;
    cin >> l >> r;
    auto it_r = upper_bound(x.begin(), x.end(), r); // Find the first element greater than r
    auto it_l = lower_bound(x.begin(), x.end(), l); // Find the first element not less than l
    
    int rt = it_r - x.begin(); // Calculate the index using iterator arithmetic
    int lt = it_l - x.begin();
    
    if(lt >= n || rt == 0) { // Check for edge cases where l or r might be out of bounds after sorting
      cout << "0" << endl;
    } else {
      int ans = s[rt] - s[lt]; // Calculate the sum between indices
      cout << ans << endl;
    }
  }
  return 0;
}