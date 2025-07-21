#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  // Calculate the difference between the largest and smallest possible sums after removing k elements
  long long min_diff = LLONG_MAX;
  for (int i = 0; i <= n - k; i++) {
    min_diff = min(min_diff, arr[i + k - 1] - arr[i]);
  }

  cout << min_diff << endl;
  return 0;
}