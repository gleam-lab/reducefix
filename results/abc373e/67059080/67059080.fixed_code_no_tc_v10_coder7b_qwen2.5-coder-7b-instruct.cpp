#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
  ll val;
  int idx;
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;

  vector<Node> a(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  sort(a.begin() + 1, a.begin() + N + 1, [](const Node& A, const Node& B) {
    return A.val < B.val;
  });

  vector<ll> pre(N + 1);
  pre[0] = 0LL;
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + a[i].val;
  }

  K -= pre[N];

  vector<ll> ans(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    if (a[i].val + K >= pre[N] - pre[i]) {
      ans[a[i].idx] = 0;
      continue;
    }
    ll left = a[i].val + 1, right = K;
    while (left < right) {
      ll mid = (left + right) / 2;
      if (mid + a[i].val > pre[N] - pre[i] - (N - i)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    ans[a[i].idx] = left - a[i].val - 1;
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;

  return 0;
}