#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  // Remove the largest k/2 elements and smallest k/2 elements
  int ans = a[n-k/2] - a[k/2];
  
  cout << ans << endl;
  return 0;
}