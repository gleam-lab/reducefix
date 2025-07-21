#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<ll> p(n), prefix_sum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    prefix_sum[i + 1] = prefix_sum[i] + p[i];
  }

  int q;
  cin >> q;

  // Process each query using binary search on x to find the relevant indices
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    // Find first index in x >= l
    auto left_it = lower_bound(x.begin(), x.end(), l);
    int left_idx = distance(x.begin(), left_it);

    // Find first index in x > r
    auto right_it = lower_bound(x.begin(), x.end(), r + 1);
    int right_idx = distance(x.begin(), right_it);

    // Sum p from left_idx to right_idx - 1 in prefix_sum
    ll result = prefix_sum[right_idx] - prefix_sum[left_idx];
    cout << result << '\n';
  }

  return 0;
}