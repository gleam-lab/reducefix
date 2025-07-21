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

  vector<ll> res(N, -1);

  // Create a list of (votes, index)
  vector<pair<ll, int>> candidates(N);
  for (int i = 0; i < N; ++i) {
    candidates[i] = {A[i], i};
  }

  // Sort by votes descending
  sort(candidates.rbegin(), candidates.rend());

  // For each candidate, determine how many additional votes they need
  for (int i = 0; i < N; ++i) {
    auto [base_votes, idx] = candidates[i];
    ll need = 0;

    // Count how many candidates currently have more votes
    int stronger = 0;
    for (int j = 0; j < N; ++j) {
      if (A[j] > base_votes) {
        stronger++;
      }
    }

    if (stronger < M) {
      res[idx] = 0;
      continue;
    }

    // Need to ensure at least (stronger - (M-1)) candidates are overtaken
    int target_overtake = stronger - (M - 1);
    if (target_overtake <= 0) {
      res[idx] = 0;
      continue;
    }

    // Collect the votes of the top `target_overtake` candidates we need to beat
    vector<ll> to_beat;
    for (int j = 0; j < N; ++j) {
      if (A[j] > base_votes) {
        to_beat.push_back(A[j]);
        if ((int)to_beat.size() == target_overtake) break;
      }
    }

    // Binary search on the number of extra votes needed
    ll low = 1, high = remaining;
    while (low <= high) {
      ll mid = (low + high) / 2;
      ll new_vote = base_votes + mid;

      // How many of the top candidates does this overtake?
      int overtaken = 0;
      for (int j = 0; j < target_overtake; ++j) {
        if (new_vote > to_beat[j]) {
          overtaken++;
        } else {
          // Since sorted descending, can break early
          break;
        }
      }

      if (overtaken >= target_overtake) {
        high = mid - 1;
        need = mid;
      } else {
        low = mid + 1;
      }
    }

    if (need == 0 && base_votes + need <= candidates[M - 1].first) {
      // Special case: even with 0 extra, might not be in top M due to tie
      int rank = 0;
      for (int j = 0; j < N; ++j) {
        if (A[j] > base_votes) rank++;
      }
      if (rank >= M) {
        // Still not in top M even after tie-breaking
        // We need at least one more vote to break tie
        need = 1;
      }
    }

    if (need <= remaining) {
      res[idx] = need;
    } else {
      res[idx] = -1;
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";

  return 0;
}