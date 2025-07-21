#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> prefix(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> prefix[i + 1];
    prefix[i + 1] += prefix[i];
  }
  
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin();
    int lt = lower_bound(x.begin(), x.end(), l) - x.begin();
    if (lt >= rt) {
      cout << "0\n"; // Ensure that we do not have an empty range
    } else {
      cout << prefix[rt] - prefix[lt] << "\n";
    }
  }
  return 0;
}