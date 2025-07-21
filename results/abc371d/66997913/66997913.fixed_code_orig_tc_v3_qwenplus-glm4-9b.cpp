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
    if (i > 0)
      s[i+1] = s[i] + p[i];  // Start accumulate from s[1] to avoid s[0] being initialized to zero
    else
      s[i+1] = p[i];        // Initialize s[1] with p[0]
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    // Ensure that we don't provide an answer for the case where l = r (shouldn't happen with correct input)
    if (lt <= rt) {
      ll ans = s[rt] - s[lt]; // Subtract the cumulative sum at 'rt' and 'lt' to get the sum for the range
      cout << ans << endl;
    } else {
      cout << "Invalid range" << endl; // In case of an invalid range
    }
  }
  return 0;
}