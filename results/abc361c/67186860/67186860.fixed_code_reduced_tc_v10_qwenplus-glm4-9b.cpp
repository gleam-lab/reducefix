#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  // Sort the vector
  sort(a.begin(), a.end());
  
  // If k is greater than half of n, removing the k smallest will make the minimum of B very large
  // Thus, in this case, we should remove the k largest elements instead.
  if (k > n / 2) {
    // Remove k largest elements from the end of the sorted array
    for (int i = 0; i < k; i++) {
      a.pop_back();
    }
  } else {
    // Remove the first k smallest elements from the start of the sorted array
    a.erase(a.begin(), a.begin() + k);
  }
  
  // Calculate the minimum possible value of the maximum and minimum of B
  int min_value = *a.begin();
  int max_value = *a.end() - 1;
  
  cout << max_value - min_value << endl;
  return 0;
}