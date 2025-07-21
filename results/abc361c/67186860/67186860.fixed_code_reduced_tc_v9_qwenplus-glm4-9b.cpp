#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  
  sort(A.begin(), A.end());
  
  // Priority queue to keep track of the largest value in the current window
  priority_queue<int> maxHeap;
  // Priority queue to keep track of the smallest value in the current window
  priority_queue<int, vector<int>, greater<int>> minHeap;
  
  // Initialize the first window
  for (int i = 0; i < n; i++) {
    maxHeap.push(A[i]);
    minHeap.push(A[i]);
    
    // If the window size exceeds N-K, remove the oldest element from both heaps
    if (i >= n - k) {
      maxHeap.pop();
      minHeap.pop();
    }
    
    // Once the window size is N-K, calculate the max and min of the window
    if (i >= n - k - 1) {
      // The difference between the top of the maxHeap and minHeap gives the range of the window
      int maxVal = maxHeap.top();
      int minVal = minHeap.top();
      cout << maxVal - minVal << endl;
    }
  }
  
  return 0;
}