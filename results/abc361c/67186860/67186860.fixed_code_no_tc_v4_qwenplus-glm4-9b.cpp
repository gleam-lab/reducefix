#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  // We use two pointers to find the optimal subsequence of length n-k
  int left = 0, right = n - 1;
  int max_dist = 0;
  
  // We iterate while we have more than k elements to remove
  while (right - left + 1 > k) {
    int local_max = 0, local_min = INT_MAX;
    
    // Find the local max and min in the current window of elements
    for (int i = left; i <= right; i++) {
      local_max = max(local_max, A[i]);
      local_min = min(local_min, A[i]);
    }
    
    // Update the maximum distance between the local max and min
    max_dist = max(max_dist, local_max - local_min);
    
    // Move the pointers to the right to get a new window
    left++;
    right--;
  }
  
  // After narrowing down to a window, we need to check the last window's max_dist
  if (right - left + 1 <= k) {
    int local_max = 0, local_min = INT_MAX;
    
    // Find the local max and min in the last window
    for (int i = left; i <= right; i++) {
      local_max = max(local_max, A[i]);
      local_min = min(local_min, A[i]);
    }
    
    max_dist = max(max_dist, local_max - local_min);
  }
  
  cout << max_dist << endl;
  return 0;
}