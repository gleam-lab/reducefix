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

  vector<Node> a(N + 5);
  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  auto cmp = [](const auto &A, const auto &B) -> bool {
    return A.val > B.val;
  };
  sort(a.begin() + 1, a.begin() + N + 1, cmp);

  vector<ll> prefix(N + 5), suffix(N + 5);
  prefix[0] = suffix[N] = 0;
  for (int i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + a[i].val;
  }
  for (int i = N - 1; i >= 0; --i) {
    suffix[i] = suffix[i + 1] + a[i].val;
  }

  vector<ll> ans(N + 5);
  for (int i = 1; i <= N; ++i) {
    ll remaining_votes = K - prefix[i];
    int num_candidates_left = N - i;
    if (num_candidates_left < M) {
      ans[a[i].idx] = 0;
      continue;
    }
    ll target = a[i].val + 1;
    ll left_needed = target * (M - 1) - suffix[i + 1];
    ll right_needed = (prefix[N] - prefix[i]) - (target * num_candidates_left - remaining_votes);
    ans[a[i].idx] = max(left_needed, right_needed);
    if (ans[a[i].idx] < 0) ans[a[i].idx] = -1;
  }

  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}