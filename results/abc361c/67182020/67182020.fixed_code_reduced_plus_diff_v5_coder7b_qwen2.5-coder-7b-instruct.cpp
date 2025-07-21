#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  sort(A.begin(), A.end());

  int min_diff = INT_MAX;
  for (int i = 0; i <= N - K; ++i) {
    int max_val = A[i + K - 1];
    int min_val = A[i];
    int diff = max_val - min_val;
    min_diff = min(min_diff, diff);
  }

  cout << min_diff << endl;
  return 0;
}