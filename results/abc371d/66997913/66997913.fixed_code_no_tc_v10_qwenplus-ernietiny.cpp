#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // Read number of elements in x vector
  vector<int> x(n); // Initialize x vector with input
  
  // Fix the algorithm to calculate the sum of numbers in x after processing the range [l, r]
  // Instead of using upper_bound and lower_bound directly, we can iterate through the range and calculate the sum of elements within the range.
  int sum = 0; // Initialize sum variable to store the sum of elements in the range [l, r]
  for (int i = 0; i < n; i++) { // Iterate through each element in x
    sum += x[i]; // Add each element to the sum
    // Now calculate the correct value for the answer by subtracting the element at index rt from the sum of elements in the range [l, r]
    int ans = sum - (lower_bound(x.begin(), x.end(), r) - x.begin()); // Corrected calculation of answer
    cout << ans << endl; // Output the correct answer
  }
  return 0;
}