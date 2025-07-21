#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  // Sort the array
  sort(A.begin(), A.end());

  // We need to find the minimum possible range of the remaining elements after removing K elements
  // The best strategy is to remove the largest K elements if K is odd, or the largest K-1 elements and the largest element if K is even
  int min_value = A[k-1]; // The minimum value of the remaining elements
  int max_value = A[n-k]; // The maximum value of the remaining elements

  // Calculate the result
  int result = max_value - min_value;

  // Output the result
  cout << result << endl;

  return 0;
}