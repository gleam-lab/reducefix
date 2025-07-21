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
  
  // Remove the smallest k/2 elements and the largest k/2 elements
  for (int i = 0; i < k / 2; i++) {
    dq.pop_back();
    dq.pop_front();
  }

  // If k is odd, we need to consider one more element from the middle
  if (k % 2 == 1) {
    // Calculate the difference between the maximum and minimum values after removals
    int ans = min(dq.back() - dq.front(), dq[dq.size()-2] - dq[1]);
    cout << ans << endl;
  } else {
    // If k is even, simply output the difference between the two extreme values left
    cout << dq.back() - dq.front() << endl;
  }

  return 0;
}