#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), s(n + 1, 0); // Initialize s with 0 to avoid undefined behavior when calculating cumulative sum
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s[i + 1] = s[i] + p[i]; // Corrected line: add p[i] to s[i] to calculate cumulative sum
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // Binary search to find the indices of l and r in the sorted array x
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // Corrected line: subtract 1 to get the correct index for r
    ll ans = s[rt] - s[lt]; // Calculate the difference in cumulative sum for the range [l, r)
    cout << ans << endl;
  }
  return 0;
}