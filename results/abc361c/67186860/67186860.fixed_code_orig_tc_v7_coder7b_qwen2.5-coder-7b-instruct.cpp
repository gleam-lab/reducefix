#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for(int i = 0; i < n; ++i) cin >> v[i];
  
  // Sort the array
  sort(v.begin(), v.end());

  // Calculate the initial range (max - min)
  long long ans = v[n - 1] - v[0];

  // Try removing each element and calculate the new range
  for(int i = 0; i <= n - k; ++i) {
    long long new_min = v[i + k]; // The new minimum after removal
    long long new_max = v[n - 1]; // The maximum remains the same
    ans = min(ans, new_max - new_min); // Update the answer with the minimum range found
  }

  cout << ans << '\n';
  return 0;
}