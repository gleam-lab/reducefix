#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n, k, ans;
vector<pair<int, int>> a;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    a.clear();
    cin >> n >> k;
    ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      a.emplace_back(y, x);
    }
    sort(a.begin(), a.end());
    if (k == 1) {
      ans = a[0].second * a[0].first;
    } else {
      long long sum = 0, max_b = a[0].first, max_sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += a[i].first;
        if (sum - max_sum > k - 1) {
          break;
        }
        if (a[i].first == max_b && (sum - max_sum) % (k - 1) == 0) {
          max_sum = sum;
          max_b = a[i].second;
          ans = min(ans, max_b * max_sum);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}