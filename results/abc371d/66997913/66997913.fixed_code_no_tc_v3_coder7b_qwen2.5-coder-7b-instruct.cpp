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
    s[i+1] = s[i]+p[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(x.begin(), x.end(), l);
    auto itr = upper_bound(x.begin(), x.end(), r);
    if(itl == x.end() || itr == x.begin()) { // Handle out-of-bound scenarios
        cout << 0 << endl;
        continue;
    }
    int idxl = itl - x.begin();
    int idxr = itr - x.begin() - 1;
    ll ans = s[idxr+1] - s[idxl];
    cout << ans << endl;
  }
  return 0;
}