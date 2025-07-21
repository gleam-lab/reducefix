#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  // Sort the array to facilitate finding the minimum difference
  sort(a.begin(), a.end());
  
  // Initialize the result with the largest possible difference
  int ans = a[n-1] - a[0];
  
  // Iterate through the sorted array to find the minimum possible difference
  for (int i = 0; i <= n-k; i++) {
    ans = min(ans, a[i+k-1] - a[i]);
  }
  
  cout << ans << endl;
  return 0;
}