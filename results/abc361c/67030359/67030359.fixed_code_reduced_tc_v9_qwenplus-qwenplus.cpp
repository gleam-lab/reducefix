#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  // We will use a sliding window of size (N - K)
  int window_size = N - K;
  int min_diff = numeric_limits<int>::max();

  // We need to consider every consecutive subsequence of length (N-K)
  // and find the one with the minimal (max - min)

  // To do this efficiently, we'll use two heaps (min and max heap)
  // and a sliding window approach.

  multiset<int> window;
  for (int i = 0; i < N; ++i) {
    window.insert(A[i]);

    if (i >= window_size - 1) {
      // Calculate max - min in current window
      int current_diff = *window.rbegin() - *window.begin();
      min_diff = min(min_diff, current_diff);

      // Move window forward by removing the element leaving it
      window.erase(window.find(A[i - (window_size - 1)]));
    }
  }

  cout << min_diff << endl;
  return 0;
}