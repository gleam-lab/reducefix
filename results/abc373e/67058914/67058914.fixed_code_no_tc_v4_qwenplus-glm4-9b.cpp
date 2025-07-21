#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  long long val;
  int idx;
};

bool cmp(const Node& a, const Node& b) {
  return a.val > b.val; // Sort in descending order
}

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;

  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A.begin(), A.end(), cmp); // Sort votes received by candidates in descending order

  // Calculate remaining votes
  long long total_votes = 0;
  for (int i = 0; i < N; ++i) {
    total_votes += A[i];
  }

  // If there are already M or more candidates with more votes than the current candidate, they cannot win
  for (int i = 0; i < N; ++i) {
    if (i < M) {
      cout << 0 << " ";
    } else {
      // Calculate votes needed to at least be in the top M
      long long votes_needed = 0;
      long long votes_to_pass = A[i] + 1;
      for (int j = i + 1; j < M; ++j) {
        votes_needed += votes_to_pass - A[j];
      }

      // Check if it's possible to get these votes
      long long additional_votes_needed = votes_needed - (K - total_votes);
      if (additional_votes_needed <= 0) {
        cout << 0 << " ";
      } else if (additional_votes_needed > (K - total_votes)) {
        cout << -1 << " ";
      } else {
        cout << additional_votes_needed << " ";
      }
    }
  }

  return 0;
}