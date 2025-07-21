#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // Number of elements in x vector
  vector<int> x(n);
  // Fill x with sample input values
  for (int i = 0; i < n; i++) cin >> x[i];
  
  // Define function to calculate sum of all elements in the sorted range [l, r]
  int sum(int l, int r) {
    int sum = 0;
    for (int x_val : x) {
      if (x_val >= l && x_val <= r) sum += x_val;
    }
    return sum;
  }
  
  // Handle query case correctly with range upper bound calculation
  int q;
  cin >> q; // Number of queries
  for (int i = 0; i < q; i++) { // Loop through each query
    int l, r; // Range bounds for query
    cin >> l >> r; // Read query range bounds
    // Calculate range upper bound based on sorted vector x
    int upperBound = upper_bound(x.begin(), x.end(), r); // Should return the correct index for upper_bound function
    // Calculate range lower bound based on vector indices in s array
    int lowerBound = lower_bound(x.begin(), x.end(), l); // Should return the correct index for lower_bound function
    // Calculate the difference between the two bounds and store in answer variable
    int ans = s[upperBound] - s[lowerBound]; // Corrected code to calculate the difference between the two bounds of the sorted range [l, r]
    cout << ans << endl; // Output the correct answer for the query range
  }
  return 0;
}