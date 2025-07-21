#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  // We need to remove exactly K elements
  // To minimize max(B) - min(B), we can consider several strategies,
  // but the optimal is to try combinations of top and bottom K+1 elements

  // Since only K elements are removed, N - K elements remain.
  // So B will have length N - K.

  // The idea: choose a window of N-K elements such that the window has smallest difference
  // between max and min. But we must preserve order.

  // However, since we can only remove up to K elements, we cannot do sliding window naively.

  // Better approach:
  // Since we're allowed to remove any K elements, not necessarily from ends,
  // the best strategy is to sort the array and consider choosing a continuous segment
  // of size N-K (since removing K elements arbitrarily, we could keep any subset),
  // and among all possible segments of size N-K in the sorted array,
  // find the one with minimum (max - min)

  sort(A.begin(), A.end());

  int min_diff = numeric_limits<int>::max();
  int window_size = n - k;

  for (int i = 0; i + window_size <= n; ++i) {
    min_diff = min(min_diff, A[i + window_size - 1] - A[i]);
  }

  cout << min_diff << endl;
  return 0;
}