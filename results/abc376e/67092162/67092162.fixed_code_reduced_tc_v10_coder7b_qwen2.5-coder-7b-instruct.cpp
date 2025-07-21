#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first != p2.first) return p1.first > p2.first;
  return p1.second < p2.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    long long sum = 0, ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v[i] = {a[i], i};
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
      v[i].first *= b[i];
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    multiset<long long> ms;
    for (int i = 0; i < k; i++) {
      sum += v[i].second;
      ms.insert(v[i].second);
    }

    ans = min(ans, sum * v[k - 1].first / v[k - 1].second);

    for (int i = k; i < n; i++) {
      sum -= *ms.begin();
      ms.erase(ms.begin());
      sum += v[i].second;
      ms.insert(v[i].second);
      ans = min(ans, sum * v[i].first / v[i].second);
    }

    cout << ans << "\n";
  }
  return 0;
}