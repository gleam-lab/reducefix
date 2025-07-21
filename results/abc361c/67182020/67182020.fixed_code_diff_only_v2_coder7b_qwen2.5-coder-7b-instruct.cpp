#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  int result = INT_MAX;
  for(int i = 0; i <= N - K; ++i) {
    result = min(result, A[i + K - 1] - A[i]);
  }

  cout << result << '\n';

  return 0;
}