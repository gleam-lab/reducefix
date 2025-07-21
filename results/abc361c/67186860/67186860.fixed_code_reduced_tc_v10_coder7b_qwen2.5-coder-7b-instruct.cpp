#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  // Sort the array first
  sort(v.begin(), v.end());

  // We need to find the minimum possible value of the maximum value of B minus the minimum value of B
  // This can be achieved by removing the smallest k/2 elements and the largest k/2 elements
  int result = v[n-k/2] - v[k/2];

  cout << result << endl;
  return 0;
}