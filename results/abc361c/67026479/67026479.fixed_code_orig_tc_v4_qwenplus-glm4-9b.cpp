#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, K;
  vector<int> A;

  cin >> n >> K;
  A.resize(n);
  for (int i = 0; i < n; ++i) cin >> A[i];

  // Sort the vector
  sort(A.begin(), A.end());

  int min_diff = INT_MAX;

  // Iterate over the possible positions to remove K elements
  for (int i = 0; i <= n - K; ++i) {
    int min_val = A[i];  // minimum value of the remaining sequence
    int max_val = A[i + K - 1];  // maximum value of the remaining sequence
    int diff = max_val - min_val;
    min_diff = min(min_diff, diff);
  }

  cout << min_diff << endl;

  return 0;
}