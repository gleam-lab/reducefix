#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Node {
  ll val;
  int idx;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K;
  cin >> N >> M >> K;

  vector<Node> A(N + 1);
  ll sum = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i].val;
    sum += A[i].val;
    A[i].idx = i;
  }

  sort(A.begin() + 1, A.begin() + N + 1, [](const Node& a, const Node& b) {
    return a.val < b.val;
  });

  vector<ll> remaining_votes(N + 1);
  remaining_votes[0] = 0;
  for (int i = 1; i <= N; ++i) {
    remaining_votes[i] = K - remaining_votes[i - 1];
  }

  vector<ll> votes_needed(N + 1);
  for (int i = N; i >= 1; --i) {
    ll votes_to_win = sum + i - A[i].val;
    ll remaining_votes_suffix = min(remaining_votes[i - 1], votes_to_win - A[i].val);

    if (remaining_votes_suffix >= (i - 1) - A[i].idx + M) {
      votes_needed[A[i].idx] = votes_to_win - A[i].val - remaining_votes_suffix;
    } else {
      votes_needed[A[i].idx] = -1;
    }

    sum -= A[i].val;
  }

  for (int i = 1; i <= N; ++i) {
    if (votes_needed[i] == -1) {
      cout << -1 << ' ';
    } else {
      cout << votes_needed[i] << ' ';
    }
  }
  cout << '\n';

  return 0;
}