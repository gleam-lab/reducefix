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

  // We are removing exactly K elements
  // So we keep (N - K) elements
  // The optimal strategy is to remove some number of elements from the left and right ends
  // Try all possible ways: remove i elements from left, and (K - i) from right
  int ans = A[N - 1] - A[0]; // worst case: no improvement
  
  for (int i = 0; i <= K; i++) {
    int left = i;           // remove i elements from left
    int right = N - 1 - (K - i); // remove (K-i) elements from right
    if (left <= right) {
      chmin(ans, A[right] - A[left]);
    }
  }

  cout << ans << endl;
  return 0;
}