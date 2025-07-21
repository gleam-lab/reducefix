#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // Sort the array to easily find the smallest and largest elements after removal
  sort(v.begin(), v.end());

  // The optimal strategy is to remove the K smallest elements
  // This way, the difference between the maximum and minimum of the remaining elements will be minimized
  long long ans = v[n-1] - v[k];

  cout << ans << endl;
  return 0;
}