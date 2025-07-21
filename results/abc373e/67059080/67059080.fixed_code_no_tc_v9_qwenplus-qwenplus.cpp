#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  ll K;
  cin >> N >> M >> K;

  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  ll total_current = accumulate(A.begin(), A.end(), 0LL);
  ll remaining = K - total_current;

  vector<ll> sorted_A = A;
  sort(sorted_A.begin(), sorted_A.end());

  vector<ll> prefix(N + 1);
  for (int i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + sorted_A[i - 1];
  }

  vector<ll> res(N);

  for (int i = 0; i < N; ++i) {
    ll cur_votes = A[i];

    // Binary search on the minimum number of additional votes needed
    ll low = 0, high = remaining;
    ll answer = -1;

    while (low <= high) {
      ll mid = (low + high) / 2;
      ll new_votes = cur_votes + mid;
      ll left_remaining = remaining - mid;

      // We want to find how many candidates can have >= new_votes
      // All such candidates would be those who can potentially be above i

      // Find first index in sorted_A where value >= new_votes
      int idx = lower_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();

      // There are (N - idx) candidates with >= new_votes excluding current one if not already counted
      // Now we need to check if at most M-1 candidates can have strictly more than new_votes
      // So that at least (N - (M-1)) candidates have <= new_votes including i
      // That ensures i is among top M

      // To make sure candidate i is elected, there must be at least (M) candidates with <= new_votes
      // which means at most (N - M) candidates can have > new_votes

      // If current candidate's vote count is new_votes,
      // then we want at most (M-1) candidates with more than new_votes => at least (N - M + 1) candidates with <= new_votes

      // We already have (idx) candidates with <= new_votes
      // But some of them might get extra votes

      // The worst case: assign as much as possible from left_remaining to the smallest A[j]s up to index idx - 1
      // Try to make as many of them exceed new_votes as possible

      // Total needed to make `x` candidates in [0..idx-1] reach > new_votes:
      // sum_{j=0}^{x-1} (new_votes - A[j] + 1)

      // Use binary search to find max x s.t. this sum <= left_remaining
      int l = 0, r = idx;
      int x = 0;
      while (l <= r) {
        int m = (l + r) / 2;
        ll need = m * new_votes - (prefix[m] - prefix[0]) + m;
        if (need <= left_remaining) {
          x = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }

      // After adding up to x candidates from lower end, we have:
      // (N - idx): candidates already > new_votes
      // x: additional ones made > new_votes via leftover votes
      ll total_more = (N - idx) + x;

      if (total_more < M) {
        answer = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (answer == -1) {
      res[i] = -1;
    } else {
      res[i] = answer;
    }
  }

  for (ll val : res) {
    cout << val << " ";
  }
  cout << "\n";

  return 0;
}