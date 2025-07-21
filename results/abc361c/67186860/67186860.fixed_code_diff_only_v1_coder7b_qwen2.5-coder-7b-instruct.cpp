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
  
  // We need to remove k elements such that the difference between the max and min of the remaining elements is minimized.
  // To achieve this, we can either remove the k smallest elements or the first k elements (since removing the smallest elements will leave us with larger numbers).
  int ans = min(arr[n-k-1] - arr[0], arr[n-1] - arr[k]);
  
  cout << ans << endl;
  return 0;
}