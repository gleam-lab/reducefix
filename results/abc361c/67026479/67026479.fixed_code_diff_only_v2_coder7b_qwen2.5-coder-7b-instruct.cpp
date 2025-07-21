#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  sort(a.begin(), a.end());
  
  long long min_diff = LLONG_MAX;
  
  for(int i = 0; i <= n - k; i++) {
    min_diff = min(min_diff, static_cast<long long>(a[i + k - 1]) - a[i]);
  }
  
  cout << min_diff << endl;
  
  return 0;
}