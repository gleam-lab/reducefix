#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n; // Number of elements in the vector x
  vector<int> x(n); // Vector of integers
  for (int i = 0; i < n; i++) {
    cin >> x[i]; // Read elements from the input
  }
  vector<ll> p(n), s(n+1); // Vector of long long numbers for comparison
  // Compute differences and sum the vector elements for calculation
  ll totalSum = accumulate(x.begin(), x.end(), 0LL); // Sum of the differences in the vector s
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i] + (ll)i * (x[i] - totalSum); // Update the sum of the differences in the vector s based on the current element
  }
  
  int q; // Number of queries
  cin >> q; // Read the number of queries
  while (q--) {
    int l, r; // Input from the query
    cin >> l >> r; // Read the two elements for the query
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin(); // Find the index of the element in the sorted array x that is less than or equal to r
    int lt = lower_bound(s.begin(), s.end(), l) - s.begin(); // Find the index of the element in the sorted vector s that is less than l
    // Calculate difference between two elements and store in answer variable
    int ans = s[rt] - s[lt]; // Answer should be either positive or negative depending on whether the element is present or absent in x
    cout << ans << endl; // Output the result of the query
  }
  return 0;
}