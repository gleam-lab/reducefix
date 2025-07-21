#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dq.push_back(a);
  }
  sort(dq.begin(), dq.end());
  
  // Remove the smallest k elements
  while(k--) {
    dq.pop_front();
  }
  
  // The result will be the difference between the largest and smallest element left
  int ans = dq.back() - dq.front();
  cout << ans << endl;
  return 0;
}