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
  
  for (int i = 0; i < k/2; i++) {
    dq.pop_back();
    dq.pop_front();
  }
  
  int m = dq.size();
  int ans = 0;
  if (k%2 == 1) {
    ans = min(dq[m-2]-dq[0], dq[m-1]-dq[1]);
  } else {
    ans = dq[m-1]-dq[0];
  }
  cout << ans << endl;
  return 0;
}