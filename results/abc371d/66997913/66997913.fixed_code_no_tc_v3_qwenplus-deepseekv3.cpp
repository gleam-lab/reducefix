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
    // Find first x >= l
    int left = lower_bound(x.begin(), x.end(), l) - x.begin();
    // Find first x > r, then subtract 1 to get last x <= r
    int right = upper_bound(x.begin(), x.end(), r) - x.begin();
    right--;  // Now right points to last element <= r
    
    ll sum = 0;
    if (left <= right && right >= 0 && left < n) {
      sum = prefix[right+1] - prefix[left];
    }
    cout << sum << '\n';
  }
  return 0;
}