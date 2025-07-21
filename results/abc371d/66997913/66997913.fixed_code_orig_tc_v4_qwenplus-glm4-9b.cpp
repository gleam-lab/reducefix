#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    // Ensure that the bounds are within the array
    if (lt >= n) lt = n - 1;
    if (rt > n) rt = n;
    ll sum = 0;
    if (rt > 0) sum += p[rt - 1];  // Sum up to the element just before r
    if (lt > 0) sum -= p[lt - 1];  // Subtract the element just before l
    cout << sum << endl;
  }
  return 0;
}