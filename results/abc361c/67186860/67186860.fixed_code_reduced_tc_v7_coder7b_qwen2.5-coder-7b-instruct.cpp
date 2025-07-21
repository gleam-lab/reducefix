#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  // Sort the array
  sort(v.begin(), v.end());

  // The optimal strategy is to remove the smallest k/2 elements and the largest k/2 elements
  long long ans = v[n-k/2] - v[k/2];

  cout << ans << endl;
  return 0;
}