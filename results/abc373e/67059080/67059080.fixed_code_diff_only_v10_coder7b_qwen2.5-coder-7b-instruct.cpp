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
  cout.tie(nullptr);

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
  for (int i = 1; i <= N; ++i) {
    pre[i] = pre[i - 1] + a[i].val;
  }

  K -= pre[N];
  if (K < 0) {
    for (int i = 1; i <= N; ++i) {
      cout << -1 << ' ';
    }
    return 0;
  }

  vector<ll> ans(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    if (a[i].val + K < a[i].val + 1) {
      continue;
    }
    int idx = upper_bound(a.begin() + i + 1, a.begin() + N + 1, (Node{a[i].val + K, 0})) - a.begin();
    int cnt = N - idx + 1;
    if (cnt < M) {
      ans[i] = 0;
    } else {
      int left = 0, right = K;
      while (left < right) {
        int mid = (left + right) / 2;
        if (a[i].val + mid + (N - idx + 1) < a[i].val + mid + 1) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      ans[i] = left - 1;
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[a[i].idx] << ' ';
  }

  return 0;
}