#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  // Sort the array to easily find the minimum and maximum of the remaining elements
  sort(a.begin(), a.end());
  
  // The smallest difference will be either between the smallest remaining element
  // and the largest removed element, or the largest remaining element and the smallest removed element.
  // Since we need to remove k elements, we consider the smallest k elements (which are removed)
  // and the largest k elements (which remain) to calculate the minimum difference.
  
  int min_diff = INT_MAX;
  
  // Check the difference between the min of the remaining elements and the max of the removed elements
  int remove_min = a[k];
  int remain_max = a[n - k - 1];
  min_diff = min(min_diff, remain_max - remove_min);
  
  // Check the difference between the max of the remaining elements and the min of the removed elements
  remove_min = a[0];
  remain_max = a[n - k - 2];
  min_diff = min(min_diff, remain_max - remove_min);
  
  cout << min_diff << endl;
}