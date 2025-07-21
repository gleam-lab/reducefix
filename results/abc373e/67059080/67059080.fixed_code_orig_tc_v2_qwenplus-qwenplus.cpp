#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  ll K;
  cin >> N >> M >> K;

  vector<pair<ll, int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first;
    A[i].second = i;
  }

  // Sorted by vote count
  vector<pair<ll, int>> sortedA = A;
  sort(sortedA.begin(), sortedA.end());

  vector<ll> prefix(N + 1);
  for (int i = 1; i <= N; ++i)
    prefix[i] = prefix[i - 1] + sortedA[i - 1].first;

  vector<ll> res(N);

  for (int i = 0; i < N; ++i) {
    ll ownVotes = A[i].first;
    int idx = lower_bound(sortedA.begin(), sortedA.end(), make_pair(ownVotes, -1)) - sortedA.begin();

    // Binary search on X: additional votes needed
    ll low = 0, high = K + 1;
    while (low < high) {
      ll mid = (low + high) / 2;
      ll newTotal = ownVotes + mid;
      ll remaining = K - mid;

      // Find how many candidates have strictly more than newTotal
      int cnt = N - (upper_bound(sortedA.begin(), sortedA.end(), make_pair(newTotal, N + 1)) - sortedA.begin());

      if (cnt >= M) {
        low = mid + 1;
        continue;
      }

      // Try to distribute the remaining votes greedily to others to try to exceed our candidate
      int pos = upper_bound(sortedA.begin(), sortedA.end(), make_pair(newTotal, N + 1)) - sortedA.begin();
      int maxCanBeat = M - cnt - 1;

      if (pos <= maxCanBeat) {
        low = mid + 1;
        continue;
      }

      ll required = newTotal * maxCanBeat - (prefix[pos] - prefix[pos - maxCanBeat]);
      if (required > remaining)
        low = mid + 1;
      else
        high = mid;
    }

    // After binary search, low is the minimal needed
    ll tempOwn = A[i].first + low;
    ll rem = K - low;
    int pos = upper_bound(sortedA.begin(), sortedA.end(), make_pair(tempOwn, N + 1)) - sortedA.begin();
    int cnt = N - pos;

    if (cnt >= M || low > K) {
      res[A[i].second] = -1;
    } else {
      res[A[i].second] = low;
    }
  }

  for (int i = 0; i < N; ++i)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}