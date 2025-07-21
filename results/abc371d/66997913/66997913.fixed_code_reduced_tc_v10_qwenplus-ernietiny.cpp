#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n; // Number of elements in the vector x
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i]; // Read elements into vector x

  vector<long long> p(n), s(n+1); // Use long long for more precise result in case of overflow
  for (int i = 0; i < n; i++) {
    cin >> p[i]; // Read the pattern value into vector p
    if (p[i] > 999984690) { // Handle overflow if pattern value is very large
      s[i+1] = p[i] / 1000000LL; // Divide by 1 million to avoid overflow in subsequent calculations
    } else {
      s[i+1] = p[i]; // Otherwise, store the pattern value directly in s[i+1]
    }
  }
  
  int q;
  cin >> q; // Number of queries to process
  vector<pair<int, int>> query; // Store the query elements and their expected results
  for (int i = 0; i < q; i++) {
    int l, r; // Query elements l and r
    cin >> l >> r; // Read the query elements into vectors l and r
    int ans = s[upper_bound(x.begin(), x.end(), r)-x.begin()] - s[lower_bound(x.begin(), x.end(), l)-x.begin()]; // Calculate the expected result
    query.push_back({l, ans}); // Store the query element and its expected result in the vector query
  }
  
  // Output the results for each query
  for (const auto& query : query) {
    cout << query.first << " " << query.second << endl; // Output the expected result for each query element
  }
  return 0;
}