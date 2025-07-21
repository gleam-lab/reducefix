#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];
pair<int, int> p[maxN];
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first < p2.first; // Ensure ascending order by A_i
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    priority_queue<int> q;
    long long sum = 0, ans = 1e18;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
      p[i].first = a[i];
      p[i].second = b[i];
    }
    sort(p + 1, p + 1 + n, cmp);
    for (int i = k; i <= n; i++) {
      sum += p[i].second;
      q.push(p[i].second);
    }
    ans = min(ans, sum * p[k].first);
    for (int i = k + 1; i <= n; i++) {
      sum -= q.top();
      q.pop();
      q.push(p[i].second);
      sum += p[i].second;
      ans = min(ans, sum * p[i].first);
    }
    cout << ans << "\n";
  }
  return 0;
}