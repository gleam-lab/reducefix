#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define ll long long

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vi A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  // We need to choose N-K elements such that the difference between max and min is minimized.
  // The idea: the minimal difference is achieved by selecting a contiguous segment of N-K elements in the sorted array.

  sort(all(A));
  int min_diff = INT_MAX;
  int window_size = N - K;
  for (int i = 0; i + window_size <= N; ++i) {
    chmin(min_diff, A[i + window_size - 1] - A[i]);
  }

  cout << min_diff << endl;
  return 0;
}