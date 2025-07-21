#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  vector<ll> s(n+1);
  for (int i = 0; i < n; i++) s[i+1] = s[i] + x[i];
  
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(x.begin(), x.end(), l);
    auto itr = upper_bound(x.begin(), x.end(), r);
    int cnt = distance(itl, itr);
    if(cnt == 0) {
      cout << 0 << '\n';
    } else {
      int idxl = itl - x.begin();
      int idxr = itr - x.begin();
      ll sum = s[idxr] - s[idxl];
      cout << sum << '\n';
    }
  }
  return 0;
}