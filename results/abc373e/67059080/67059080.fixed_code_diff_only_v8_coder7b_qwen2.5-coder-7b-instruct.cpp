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
  std::cin.tie(nullptr)->sync_with_stdio(false);
  cin >> N >> M >> K;

  vector<Node> a(N + 5);
  vector<ll> prefix(N + 5, 0);

  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
  }

  sort(a.begin() + 1, a.begin() + N + 1, [](const auto &A, const auto &B) {
    return A.val < B.val;
  });

  prefix[0] = 0;
  for (int i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + a[i].val;
  }

  K -= prefix[N];

  vector<ll> result(N + 5, 0);

  for (int i = 1; i <= N; ++i) {
    ll cur_votes = a[i].val + K;
    int remaining_candidates = N - i;
    if (remaining_candidates < M) {
      result[a[i].idx] = 0;
    } else {
      ll min_votes_needed = (K + remaining_candidates - M + 1) / remaining_candidates;
      result[a[i].idx] = max(0LL, min_votes_needed - a[i].val);
    }
  }

  for (int i = 1; i <= N; ++i) {
    cout << result[i] << ' ';
  }

  return 0;
}