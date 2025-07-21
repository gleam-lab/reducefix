#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  
  // Read the elements into a vector to preserve their original order
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  // To find the minimum possible value of the maximum value of B minus the minimum value of B,
  // we need to maximize the range (max - min) after removing K elements.
  // We should remove the smallest K elements to maximize the remaining largest and smallest elements.
  sort(A.begin(), A.end());
  
  // The answer is simply the difference between the largest and the smallest elements
  // after removing the smallest K elements.
  int ans = A[n - k] - A[k - 1];
  cout << ans << endl;
  
  return 0;
}