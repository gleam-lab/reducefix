#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  
  for(int i = 0; i < n; ++i) cin >> a[i];
  
  // If the number of elements to remove is greater than or equal to half of the array,
  // we can remove the minimum/maximum elements from either end of the array.
  if (k >= n / 2) {
    sort(a.begin(), a.end());
    cout << a[n - 1] - a[0] << endl;
  } else {
    // Otherwise, we need to find the smallest possible range after removing k elements.
    // We can do this by using a sliding window of size n-k to find the minimum difference
    // between the maximum and minimum elements in each window.
    priority_queue<int> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    
    for (int i = 0; i < n; ++i) {
      max_heap.push(a[i]);
      min_heap.push(a[i]);
      
      // If the window size is greater than k, remove the smallest and largest elements
      if (i >= k) {
        min_heap.pop();
        max_heap.pop();
      }
      
      // If we have a valid window of size n-k, calculate the difference between the
      // maximum and minimum elements.
      if (i >= k - 1) {
        cout << max_heap.top() - min_heap.top() << endl;
        break;
      }
    }
  }
}