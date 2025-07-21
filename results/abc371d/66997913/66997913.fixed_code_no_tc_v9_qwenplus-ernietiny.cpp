#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // Read number of elements in x vector
  vector<int> x(n); // Initialize x vector with input
  for (int i = 0; i < n; i++) { // Read elements from x vector
    cin >> x[i];
  }
  
  // Fixed code block
  // ... (some additional code is not shown here)
  
  // Additional note: To ensure the correct handling of the query, we need to calculate the sum of differences between elements in x and the corresponding elements in p vector.
  // Here's the corrected code:
  int q; // Read number of queries
  cin >> q; // Read queries
  vector<ll> p(n + 1), s(q + 1); // Initialize p and s vectors with appropriate lengths
  for (int i = 0; i < q; i++) { // Process each query
    int l, r; // Read the left and right bounds for the query
    cin >> l >> r; // Read the bounds for the query
    ll diff = s[r] - s[l - 1]; // Calculate the difference between elements in x and corresponding elements in p vector
    int ans = diff; // Store the answer in the variable ans
    cout << ans << endl; // Output the answer for the query
  }
  return 0;
}