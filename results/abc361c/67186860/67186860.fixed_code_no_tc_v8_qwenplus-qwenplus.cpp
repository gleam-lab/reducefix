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
  // So we will keep (n - K) elements in B
  int window_size = n - k;

  // Sort the array to find optimal min-max intervals
  sort(A.begin(), A.end());

  int result = INT_MAX;
  // Try all windows of size (n-K) in the sorted array
  for (int i = 0; i + window_size - 1 < n; ++i) {
    result = min(result, A[i + window_size - 1] - A[i]);
  }

  cout << result << endl;
  return 0;
}