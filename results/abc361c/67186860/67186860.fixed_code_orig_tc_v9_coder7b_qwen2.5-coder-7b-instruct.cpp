#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  long long ans = LLONG_MAX;
  for (int i = 0; i <= n-k; i++) {
    ans = min(ans, v[i+k-1] - v[i]);
  }
  
  cout << ans << endl;
  return 0;
}