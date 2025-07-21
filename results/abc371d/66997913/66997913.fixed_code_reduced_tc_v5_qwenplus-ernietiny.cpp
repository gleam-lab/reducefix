#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // Number of elements in x vector
  vector<int> x(n); // Corrected data structure for vector<int>
  for (int i = 0; i < n; i++) cin >> x[i]; // Corrected input for vector<int>
  
  // Sort the elements in ascending order to handle queries efficiently
  sort(x.begin(), x.end());
  
  int q;
  cin >> q; // Number of queries
  vector<pair<int, int>> query; // To store the query and its corresponding result
  for (int i = 0; i < q; i++) { // Iterate through the queries
    int l, r; // Input for the query
    cin >> l >> r; // Corrected input for queries
    int left_idx = lower_bound(x.begin(), x.end(), r) - x.begin(); // Leftmost index to compare
    int right_idx = r - 1 - left_idx; // Rightmost index for query comparison
    int result = left_idx * (r - l) + (right_idx < n - 1 ? 1 : 0); // Calculating the result
    query.push_back({result, right_idx}); // Store the query and its result index
  }
  
  // Sort the results for efficient queries later on
  sort(query.begin(), query.end(), [](auto& a, auto& b) {
    return a.first > b.first; // Sort results in ascending order for querying purposes
  });
  
  // Apply binary search to find the maximum value in the sorted range
  int max_val = *upper_bound(x.begin(), x.end(), query[0].first); // Corrected index for upper_bound() function
  cout << max_val << endl; // Output the maximum value found in the sorted range
  return 0;
}