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
  cin >> N >> M >> K;

  vector<Node> a(N + 5);

  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  auto cmp = [](const auto &A, const auto &B)->bool {
    return A.val < B.val;
  };

  sort(a.begin() + 1, a.begin() + N + 1, cmp) ;

  vector<ll> pre(N + 5);
  pre[0] = 0LL;
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + a[i].val;
  }

  K -= pre[N];

  vector<Node> ans(N + 5);
  for (int i = 1; i <= N; ++i) {
    ans[i].idx = a[i].idx;
  }

  auto get = [&](ll add, ll i, ll zan)->ll {
    ll remain = K - add;
    ll cur = a[i].val + add;
    ll tar = cur + 1;
    int L = 0, R = zan;
    while (L < R) {
      int MID = (L + R + 1) >> 1;
      ll need = tar * MID - (pre[zan] - pre[zan - MID]);
      if (zan - MID < i) {
        need -= (add + 1);
      }
      if (need > remain) R = MID - 1;
      else L = MID;
    }
    return L - (zan - L < i);
  } ;

  for (int i = 1; i <= N; ++i) {
    ll cur = a[i].val + K;
    int idx = upper_bound(a.begin() + i + 1, a.begin() + N + 1, (Node) {cur, 0}, cmp) - a.begin();
    int cnt = (N - idx + 1);
    if (cnt >= M) {
      ans[i].val = -1;
      continue;
    }
    int l = 0, r = K;
    while (l < r) {
      int mid = (l + r) >> 1;
      cur = a[i].val + mid;
      idx = upper_bound(a.begin() + i + 1, a.begin() + N + 1, (Node) {cur, 0}, cmp) - a.begin();
      ll cnt = get(mid, i, idx - 1) + (N - idx + 1);
      if (cnt < M) r = mid;
      else l = mid + 1;
    }
    ans[i].val = l;
  }

  sort(ans.begin() + 1, ans.begin() + N + 1, [](const auto &A, const auto &B)->bool {
    return A.idx < B.idx;
  }) ;

  for (int i = 1; i <= N; ++i) {
    cout << ans[i].val << ' ';
  }

  return 0;
}