#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

int main() {
  cin >> N >> M >> K;
  vector<pair<ll, int>> A(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin() + 1, A.begin() + N + 1);

  vector<ll> prefix(N + 1);
  for (int i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + A[i].first;
  }

  vector<ll> votes_needed(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    int rank = i;
    while (rank <= N && prefix[rank] - prefix[i - 1] >= A[i].first + M - 1) {
      rank++;
    }
    if (rank > N) {
      votes_needed[A[i].second] = 0; // Already guaranteed to win
    } else {
      votes_needed[A[i].second] = M - 1 - (prefix[rank] - prefix[i - 1] - A[i].first);
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (votes_needed[A[i].second] == 0) {
      cout << 0 << " ";
    } else {
      cout << votes_needed[A[i].second] << " ";
    }
  }
  cout << endl;

  return 0;
}