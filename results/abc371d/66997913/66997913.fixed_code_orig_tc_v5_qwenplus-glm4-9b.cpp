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
    // Initialize s[0] to 0
    if (i == 0) s[i+1] = 0;
    else s[i+1] = s[i] + p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int rt = upper_bound(x.begin(), x.end(), r)-x.begin(); // Find the index in x
    int lt = (l <= x[0]) ? 0 : lower_bound(x.begin(), x.end(), l)-x.begin(); // Find the index in x, handling the case when l <= x[0]
    // Correct for when lt is 0
    int ans = (lt == 0) ? s[rt] : s[rt] - s[lt-1];
    cout << ans << endl;
  }
  return 0;
}