#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
    if(itl==x.end() || *itl > r) itr--;
    if(itr==x.begin()-1 || *itr < l) continue;
    int lt = itl-x.begin();
    int rt = itr-x.begin();
    int ans = s[rt+1]-s[lt];
    cout << ans << endl;
  }
  return 0;
}