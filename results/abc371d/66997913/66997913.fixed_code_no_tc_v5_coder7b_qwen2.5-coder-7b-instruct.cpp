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
  while(q--){
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(x.begin(), x.end(), l);
    auto itr = upper_bound(x.begin(), x.end(), r);
    if(itl == x.end() || *itl > r){
        cout << 0 << endl;
    } else{
        int idxl = itl - x.begin();
        int idxr = itr - x.begin() - 1;
        int ans = s[idxr + 1] - s[idxl];
        cout << ans << endl;
    }
  }
  return 0;
}