#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  
  // Remove k elements such that the difference between max and min is minimized
  int ans = INT_MAX;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, vec[n-k+i] - vec[i]);
  }
  cout << ans << endl;
  return 0;
}