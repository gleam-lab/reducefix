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
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M >> K;

  vector<Node> a(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  auto cmp = [](const auto &A, const auto &B) -> bool {
    return A.val < B.val;
  };
  sort(a.begin() + 1, a.begin() + N + 1, cmp);

  vector<ll> pre(N + 1);
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + a[i].val;
  }

  K -= pre[N];

  vector<ll> ans(N + 1, -1);

  for (int i = 1; i <= N; ++i) {
    if (a[i].val + K >= pre[N]) {
      ans[a[i].idx] = 0;
      continue;
    }
    int l = 0, r = K;
    while (l < r) {
      int mid = (l + r) / 2;
      ll sum = a[i].val + mid;
      int pos = lower_bound(a.begin() + i + 1, a.end(), (Node){sum, 0}, cmp) - a.begin();
      int cnt = N - pos + 1;
      if (cnt >= M) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    ans[a[i].idx] = l;
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << ' ';
  }

  return 0;
}