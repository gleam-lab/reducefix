#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  
  int q;
  cin >> q;
  vector<pair<int, int>> queries(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r};
  }
  
  sort(x.begin(), x.end());
  
  vector<ll> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i + 1] = s[i] + x[i];
  }
  
  for (auto& query : queries) {
    int l = query.first;
    int r = query.second;
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    ll ans = s[rt] - s[lt];
    cout << ans << endl;
  }
  
  return 0;
}