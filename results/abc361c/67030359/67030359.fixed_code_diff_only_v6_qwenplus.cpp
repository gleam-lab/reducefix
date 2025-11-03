#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using vi = vector<int>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N, K;
  cin >> N >> K;
  vi A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));

  // We need to remove exactly K elements, leaving N-K elements
  // The remaining elements must be contiguous in the sorted array to minimize range
  // Try all possible contiguous subarrays of length N-K
  int min_diff = INT_MAX;
  int remaining = N - K;
  
  for (int i = 0; i + remaining - 1 < N; i++) {
    chmin(min_diff, A[i + remaining - 1] - A[i]);
  }
  
  cout << min_diff << endl;
  return 0;
}