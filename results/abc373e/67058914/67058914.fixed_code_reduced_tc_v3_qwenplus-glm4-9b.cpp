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

  vector<Node> a(N + 1);
  vector<ll> A(N + 1);
  
  for (int i = 1; i <= N; ++i) {
    cin >> a[i].val;
    a[i].idx = i;
    A[i] = a[i].val;
  }

  sort(a.begin() + 1, a.begin() + N + 1, [](const Node &x, const Node &y) {
    return x.val < y.val;
  });

  ll total_votes = 0;
  for (int i = 1; i <= N; ++i) {
    ll votes_needed = M * a[i].val - (i - 1) * a[i].val;
    if (votes_needed < 0) votes_needed = 0;
    if (total_votes + votes_needed > K) {
      cout << -1 << " ";
      total_votes += votes_needed;
    } else {
      total_votes += votes_needed;
      cout << votes_needed << " ";
    }
  }

  // Calculate the minimum votes needed for the candidate who is the Mth best
  ll votes_needed = M * a[M].val - (M - 1) * a[M].val;
  if (total_votes + votes_needed > K) {
    cout << -1 << " ";
  } else {
    total_votes += votes_needed;
    cout << votes_needed << " ";
  }

  // Calculate the minimum votes needed for the remaining candidates
  for (int i = M + 1; i <= N; ++i) {
    if (total_votes + a[i].val > K) {
      cout << -1 << " ";
    } else {
      total_votes += a[i].val;
      cout << a[i].val << " ";
    }
  }

  return 0;
}