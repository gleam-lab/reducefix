#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  
  int min_diff = INT_MAX;
  for (int i = 0; i <= n - k; ++i) {
    int max_of_left = (i > 0) ? a[i - 1] : a[0];
    int min_of_right = (n - i - 1 >= 0) ? a[n - i] : a[n - 1];
    min_diff = min(min_diff, max_of_left - min_of_right);
  }

  cout << min_diff << endl;
}