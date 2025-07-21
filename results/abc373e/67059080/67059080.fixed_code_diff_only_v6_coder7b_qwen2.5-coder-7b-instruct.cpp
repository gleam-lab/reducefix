#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
  ll votes;
  int index;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;

  vector<Candidate> candidates(N);
  for (int i = 0; i < N; ++i) {
    cin >> candidates[i].votes;
    candidates[i].index = i;
  }

  // Sort candidates by the number of votes in ascending order
  sort(candidates.begin(), candidates.end());

  // Calculate the total number of votes already counted
  ll total_votes_counted = accumulate(candidates.begin(), candidates.end(), 0LL,
                                     [](ll sum, const Candidate& c) { return sum + c.votes; });

  // Remaining votes to be counted
  K -= total_votes_counted;

  // Initialize the result array
  vector<ll> results(N, -1);

  // Iterate over each candidate
  for (int i = 0; i < N; ++i) {
    ll current_votes = candidates[i].votes;
    ll remaining_candidates = N - i - 1;

    // If the current candidate has already won, set the result to 0
    if (remaining_candidates < M) {
      results[candidates[i].index] = 0;
      continue;
    }

    // Binary search to find the minimum number of additional votes needed
    ll left = 0, right = K;
    while (left < right) {
      ll mid = (left + right) / 2;
      ll hypothetical_votes = current_votes + mid;
      ll remaining_winners = M - 1;

      // Count the number of candidates who can still win with the hypothetical votes
      ll count = 0;
      for (int j = i + 1; j < N; ++j) {
        if (candidates[j].votes + mid > hypothetical_votes) {
          count++;
        }
      }

      if (count >= remaining_winners) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    results[candidates[i].index] = left;
  }

  // Output the results
  for (int i = 0; i < N; ++i) {
    cout << results[i] << " ";
  }
  cout << endl;

  return 0;
}