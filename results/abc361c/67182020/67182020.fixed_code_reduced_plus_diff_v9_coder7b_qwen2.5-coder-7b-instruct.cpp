#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  arrIn(A, 0, N);
  
  // Sort the array
  sort(A.begin(), A.end());
  
  // Initialize the minimum range with the difference of the first and last element of the sorted array
  int min_range = A[N-1] - A[0];
  
  // Use a sliding window to find the minimum range
  for (int i = 0; i <= N - K; ++i) {
    min_range = min(min_range, A[i + K - 1] - A[i]);
  }
  
  cout << min_range << endl;
  
  return 0;
}