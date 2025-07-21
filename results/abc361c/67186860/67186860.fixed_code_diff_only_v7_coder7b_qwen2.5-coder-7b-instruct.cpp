#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  
  int ans = INT_MAX;
  for (int i = 0; i <= n-k; i++) {
    ans = min(ans, arr[i+k-1] - arr[i]);
  }
  
  cout << ans << endl;
  return 0;
}