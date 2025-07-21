#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  vector<ll> p(n), prefix(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    prefix[i + 1] = prefix[i] + p[i];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    // Find first index where x[i] >= l
    int left_idx = lower_bound(x.begin(), x.end(), l) - x.begin();

    // Find first index where x[i] > r
    int right_idx = upper_bound(x.begin(), x.end(), r) - x.begin();

    ll ans = prefix[right_idx] - prefix[left_idx];
    cout << ans << endl;
  }

  return 0;
}