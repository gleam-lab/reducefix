#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // Edge case when all elements can be removed
  if (k == n - 1) {
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
    return 0;
  }

  sort(a.begin(), a.end());
  int dmin = INT_MAX;

  // Consider removing elements around the middle
  for (int i = 0; i <= n - k; i++) {
    int max_in_range = a[i + k - 1];
    int min_in_range = a[i];
    dmin = min(dmin, max_in_range - min_in_range);
  }

  cout << dmin << endl;
}