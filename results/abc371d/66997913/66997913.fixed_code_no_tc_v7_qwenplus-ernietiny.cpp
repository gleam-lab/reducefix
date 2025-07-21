#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // Read number of elements in x vector
  vector<int> x(n); // Initialize x vector with input values
  for (int i = 0; i < n; i++) {
    cin >> x[i]; // Read values from x vector
  }
  
  // Fixed code block
  int q; // Read number of queries
  cin >> q; // Read number of queries
  vector<ll> p(n), s(n+1); // Initialize p and s vectors with initial values
  for (int i = 0; i < n; i++) { // Iterate through each element in x vector
    cin >> p[i]; // Read values from p vector
    s[i+1] = p[i] + s[i]; // Update s vector with sum of elements in x vector
  }
  
  // Query processing logic here
  // ...
  // Output results for each query
  return 0;
}