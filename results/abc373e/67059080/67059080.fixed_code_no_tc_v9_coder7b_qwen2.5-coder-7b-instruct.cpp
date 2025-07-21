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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  vector<Node> a(N + 5);

  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  sort(a.begin() + 1, a.begin() + N + 1, [](const auto &A, const auto &B) -> bool {
    return A.val < B.val;
  });

  vector<ll> pre(N + 5);
  pre[0] = 0LL;
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + a[i].val;
  }

  K -= pre[N];

  vector<ll> ans(N + 5, -1);

  for (int i = 1; i <= N; ++i) {
    ll cur = a[i].val + K;
    int idx = lower_bound(a.begin() + i + 1, a.begin() + N + 1, (Node){cur, 0}, [](const auto &A, const auto &B) -> bool {
      return A.val < B.val;
    }) - a.begin();

    int cnt = (N - idx + 1);
    if (cnt < M) {
      ans[i] = 0;
    } else {
      ll need = (a[idx].val - cur) * (M - cnt) + 1;
      if (need <= K) {
        ans[i] = need;
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << ' ';
  }

  return 0;
}