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
    int left = lower_bound(x.begin(), x.end(), l) - x.begin();
    // Find first element > r, then subtract 1 to get last element <= r
    int right = upper_bound(x.begin(), x.end(), r) - x.begin();
    // The sum is from left to right-1 (inclusive)
    ll ans = prefix[right] - prefix[left];
    cout << ans << endl;
  }
  return 0;
}