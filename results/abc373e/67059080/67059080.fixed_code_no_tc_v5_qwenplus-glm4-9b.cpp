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
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> N >> M >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  // Sort candidates by their current number of votes
  vector<pair<ll, int>> sorted_candidates(N);
  for (int i = 0; i < N; ++i) {
    sorted_candidates[i] = {A[i], i + 1};
  }
  sort(sorted_candidates.begin(), sorted_candidates.end());

  // Calculate the required votes to guarantee the victory
  vector<ll> required_votes(N);
  for (int i = 0; i < N; ++i) {
    ll candidate_votes = sorted_candidates[i].first;
    ll remaining_votes = K - candidate_votes;
    ll candidates_beaten = N - i;
    if (candidates_beaten < M) {
      required_votes[i] = -1; // Cannot win even if all remaining votes go to this candidate
    } else {
      // Calculate the minimum votes needed to be above the M-th place
      ll votes_needed_to_beat_M = sorted_candidates[N - M].first + M;
      if (candidate_votes < votes_needed_to_beat_M) {
        required_votes[i] = votes_needed_to_beat_M - candidate_votes;
      } else {
        required_votes[i] = 0; // Already guaranteed victory
      }
    }
  }

  // Output the results
  for (int i = 0; i < N; ++i) {
    cout << required_votes[i] << ' ';
  }
  cout << endl;

  return 0;
}