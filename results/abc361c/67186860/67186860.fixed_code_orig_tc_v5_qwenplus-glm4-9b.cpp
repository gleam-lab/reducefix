#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  priority_queue<int, vector<int>, greater<int>> min_heap;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    min_heap.push(x);
  }

  vector<int> to_remove(n);
  int count = 0;

  while (min_heap.size() > n - k) {
    to_remove[count++] = min_heap.top();
    min_heap.pop();
  }

  sort(to_remove.begin(), to_remove.end());

  int max_diff = 0;
  for (int i = 0; i < count; ++i) {
    max_diff = max(max_diff, to_remove[i] - min_heap.top());
  }

  cout << max_diff << endl;
  return 0;
}