#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  // Sort the array to easily find the min and max values
  sort(A.begin(), A.end());
  
  // We need to remove K elements, so we can consider the cases where we remove
  // from the start or the end of the array.
  // We will calculate the difference for both cases and take the minimum.
  // Case 1: Remove the first K elements
  int case1_min = *min_element(A.begin() + k, A.end());
  int case1_max = *max_element(A.begin(), A.begin() + n - k);
  int case1_diff = case1_max - case1_min;
  
  // Case 2: Remove the last K elements
  int case2_min = *min_element(A.begin(), A.begin() + n - k);
  int case2_max = *max_element(A.begin() + k, A.end());
  int case2_diff = case2_max - case2_min;
  
  // The answer is the minimum difference from both cases
  int ans = min(case1_diff, case2_diff);
  
  cout << ans << endl;
  return 0;
}