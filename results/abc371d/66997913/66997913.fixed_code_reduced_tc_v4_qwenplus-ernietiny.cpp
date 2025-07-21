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
  // Compute differences and summation of p and s
  ll totalDiff = accumulate(p.begin(), p.end(), 0LL); // Sum of differences in vector s
  // Initialize variables for finding the maximum value in vector x
  int maxIdx = 0;
  // Iterate over elements of x and calculate the difference with the maximum value
  for (int i = 0; i < n; i++) {
    s[i+1] -= x[maxIdx]; // Subtract the maximum value from current element in vector s
    maxIdx = (maxIdx == i) ? n - 1 : (maxIdx == i + 1); // Update maxIdx to the next element if necessary
  }
  // Calculate the final answer using the formula for maximum difference in the given range
  int maxDiff = totalDiff - (s[maxIdx] - p[maxIdx]); // Use formula for finding maximum difference in the given range
  cout << maxDiff << endl; // Output the result
  return 0;
}