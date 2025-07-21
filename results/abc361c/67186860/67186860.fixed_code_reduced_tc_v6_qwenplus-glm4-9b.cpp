#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    a.push_back(a_i);
  }

  sort(a.begin(), a.end());

  priority_queue<int, vector<int>, greater<int>> min_heap;
  priority_queue<int> max_heap;

  for (int i = 0; i < n; i++) {
    min_heap.push(a[i]);

    if (min_heap.size() > (n - k)) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }

    if (max_heap.size() > (n - k)) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
  }

  int min_diff = min_heap.top() - max_heap.top();

  // Also consider the case where we remove the smallest or largest elements
  // to potentially get a smaller difference.
  min_heap.pop();
  min_heap.pop(); // Now the min_heap has the top k smallest elements
  max_heap.push(min_heap.top());
  min_heap.pop(); // Now the min_heap has the top k-1 smallest elements
  min_heap.push(a[n-1]); // Push the largest element to check if it gives a smaller difference
  min_heap.push(a[n-2]); // And now also the second smallest to have k elements

  int alternative_diff = min_heap.top() - max_heap.top();

  cout << min(min_diff, alternative_diff) << endl;

  return 0;
}