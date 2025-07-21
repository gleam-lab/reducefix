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

  // Precompute prefix sums of p
  vector<ll> s(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + p[i];
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;

    // Find the first index where x[i] >= l using lower_bound
    int left = static_cast<int>(lower_bound(x.begin(), x.end(), l) - x.begin());

    // Find the first index where x[i] > r using upper_bound
    int right = static_cast<int>(upper_bound(x.begin(), x.end(), r) - x.begin());

    // Sum p[left..right-1]
    cout << s[right] - s[left] << "\n";
  }

  return 0;
}