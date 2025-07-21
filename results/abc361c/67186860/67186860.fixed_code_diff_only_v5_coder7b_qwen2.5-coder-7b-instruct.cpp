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
  
  // Calculate the difference between the largest and smallest elements after removing k elements
  int ans = INT_MAX;
  for (int i = 0; i <= k; i++) {
    int diff = vec[n-k+i] - vec[i];
    ans = min(ans, diff);
  }
  cout << ans << endl;
  return 0;
}