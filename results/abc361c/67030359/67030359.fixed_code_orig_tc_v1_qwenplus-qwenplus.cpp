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

  // We need to choose N-K elements to keep in order
  // Our goal is to minimize max(B) - min(B)
  // Brute-force approach of the original code doesn't work because it assumes sorting helps,
  // but we must preserve the original order.

  // Let's try a sliding window approach
  int window_size = N - K;
  
  // We'll use two deques to maintain min and max in the current window
  deque<int> min_deque, max_deque;
  ll result = LLONG_MAX;

  int left = 0;
  for (int right = 0; right < N; ++right) {
    // Maintain max deque (monotonic decreasing)
    while (!max_deque.empty() && A[right] > max_deque.back()) {
      max_deque.pop_back();
    }
    max_deque.push_back(A[right]);

    // Maintain min deque (monotonic increasing)
    while (!min_deque.empty() && A[right] < min_deque.back()) {
      min_deque.pop_back();
    }
    min_deque.push_back(A[right]);

    // When window size exceeds N-K, slide window
    if (right - left + 1 > window_size) {
      if (A[left] == max_deque.front()) {
        max_deque.pop_front();
      }
      if (A[left] == min_deque.front()) {
        min_deque.pop_front();
      }
      ++left;
    }

    // Once we have a valid window, update the result
    if (right - left + 1 == window_size) {
      result = min(result, (ll)(max_deque.front() - min_deque.front()));
    }
  }

  cout << result << endl;
  return 0;
}