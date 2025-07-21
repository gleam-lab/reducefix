#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> vec(n);
  for(int i=0;i<n;i++){
      cin>>vec[i];
  }

  // Sort the array to find the minimum and maximum values easily
  sort(vec.begin(), vec.end());

  // Calculate the initial range of the sorted array
  long long max_val = vec[n - 1];
  long long min_val = vec[k];

  // Iterate through the array to consider different scenarios where removing K elements
  for(int i=k+1; i<=n-k; i++){
    long long current_max = vec[n-i];
    long long current_min = vec[i-1];
    // Update the maximum difference found so far
    max_val = max(max_val, current_max);
    min_val = min(min_val, current_min);
  }

  // Print the result which is the minimum possible difference between max and min values after removal
  cout<<max_val-min_val<<endl;
  return 0;
}