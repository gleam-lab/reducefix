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
  
  // Remove k smallest and k largest elements
  for (int i = 0; i < k; i++) {
    dq.pop_back();
    dq.pop_front();
  }
  
  // Calculate the difference between the largest and smallest element
  int ans = dq.back() - dq.front();
  cout << ans << endl;
  return 0;
}