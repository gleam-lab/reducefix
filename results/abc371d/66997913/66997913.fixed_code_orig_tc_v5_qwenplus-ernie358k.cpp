#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> s(n+1);
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i] + x[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    ll ans = s[r+1] - s[l];
    cout << ans << endl;
  }
  return 0;
}